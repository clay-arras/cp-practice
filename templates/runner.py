import sys
import glob
import os
import re
import time


GREEN = "\033[32m"
RED = "\033[31m"
BLUE = "\033[34m"
GRAY = "\033[38;5;245m"
DARK_GRAY = "\033[38;5;240m"
RESET = "\033[0m"

INFO = f"[{BLUE}INFO{RESET}]"
SUCCESS = f"[{GREEN}SUCCESS{RESET}]"
FAILURE = f"[{RED}FAILURE{RESET}]"


def _eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def _numeric_sort_key(filename):
    return [int(s) if s.isdigit() else s for s in re.split(r'(\d+)', filename)]


class InteractiveJudge:
    """Base class for interactive judges used with ``oj test-reactive``.

    Subclass and override the methods below, then call ``run()`` from
    ``__main__``.  The runner discovers ``test/*.in`` files relative to
    the calling script, pipes data to/from the solution via
    stdin/stdout, and reports results on stderr.
    """

    QUERY_PREFIXES = ('?',)
    ANSWER_PREFIX = '!'

    # ------------------------------------------------------------------
    # Override these in your subclass
    # ------------------------------------------------------------------

    def load_tests(self, file_contents: list[str]) -> list[int]:
        """Parse every ``.in`` file.  *file_contents* is a list of raw
        file texts (one per file).  Populate whatever internal state is
        needed so the other methods can look up test-case data by index.

        Return a list of ints: the number of test cases contributed by
        each file (so the runner can map TCs back to source files).
        """
        raise NotImplementedError

    def num_test_cases(self) -> int:
        raise NotImplementedError

    def preamble(self) -> list[str]:
        """Lines to send before any test case (e.g. the value of *t*)."""
        raise NotImplementedError

    def init_test_case(self, idx: int) -> list[str]:
        """Lines to send at the start of test case *idx*."""
        raise NotImplementedError

    def handle_query(self, idx: int, parts: list[str]) -> str:
        """Handle a query line.  *parts* is the split line
        (e.g. ``['?', '1', '3']``).  Return the response string."""
        raise NotImplementedError

    def check_answer(self, idx: int, parts: list[str]) -> tuple[bool, str, str]:
        """Check an answer line.  Return ``(correct, expected, output)``."""
        raise NotImplementedError

    def query_limit(self, idx: int) -> int:
        """Max queries allowed for test case *idx*.  Override per-problem."""
        return 10000

    # ------------------------------------------------------------------
    # Internal machinery
    # ------------------------------------------------------------------

    def _send(self, msg: str) -> None:
        print(msg, flush=True)
        self._log.append(('>', msg))

    def _receive(self) -> list[str] | None:
        while True:
            try:
                line = input().strip()
            except EOFError:
                return None
            if not line:
                continue
            parts = line.split()
            if parts[0] in self.QUERY_PREFIXES or parts[0] == self.ANSWER_PREFIX:
                self._log.append(('<', line))
                return parts
            _eprint(line)

    # ------------------------------------------------------------------
    # Entry point
    # ------------------------------------------------------------------

    def run(self) -> None:
        script_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
        test_dir = os.path.join(script_dir, 'test')
        test_files = sorted(
            glob.glob(os.path.join(test_dir, '*.in')),
            key=lambda p: _numeric_sort_key(os.path.basename(p)),
        )
        if not test_files:
            _eprint(f"{FAILURE} no test files in {test_dir}/")
            os._exit(1)

        file_info = []
        contents = []
        for path in test_files:
            with open(path) as fh:
                content = fh.read()
            name = os.path.splitext(os.path.basename(path))[0]
            file_info.append((name, content))
            contents.append(content)

        counts = self.load_tests(contents)
        total = self.num_test_cases()

        file_ranges = []
        offset = 0
        for i, (name, content) in enumerate(file_info):
            file_ranges.append((name, content, offset, offset + counts[i]))
            offset += counts[i]

        _eprint(f"{INFO} {len(test_files)} cases found")
        _eprint()

        # --- send preamble ------------------------------------------------
        self._log: list[tuple[str, str]] = []
        for line in self.preamble():
            self._send(line)

        # --- run all test cases, never exit early -------------------------
        tc_results: list[tuple[bool, str, str, list]] = []
        file_times: dict[str, float] = {}
        terminated = False

        for fname, _content, start, end in file_ranges:
            t0 = time.time()
            for i in range(start, end):
                if terminated:
                    tc_results.append((False, "N/A", "<terminated>", []))
                    continue

                self._log = []
                query_count = 0
                try:
                    for line in self.init_test_case(i):
                        self._send(line)

                    while True:
                        parts = self._receive()
                        if parts is None:
                            terminated = True
                            tc_results.append(
                                (False, "N/A", "<terminated>", list(self._log)))
                            break

                        if parts[0] in self.QUERY_PREFIXES:
                            query_count += 1
                            ql = self.query_limit(i)
                            if query_count > ql:
                                self._send("-1")
                                terminated = True
                                tc_results.append((
                                    False, "N/A",
                                    f"<query limit exceeded ({query_count}/{ql})>",
                                    list(self._log[-20:])))
                                break
                            self._send(self.handle_query(i, parts))
                        elif parts[0] == self.ANSWER_PREFIX:
                            ok, exp, out = self.check_answer(i, parts)
                            tc_results.append(
                                (ok, exp, out, list(self._log)))
                            break
                except BrokenPipeError:
                    terminated = True
                    tc_results.append(
                        (False, "N/A", "<pipe broken>", list(self._log)))
                except Exception as exc:
                    try:
                        self._send("-1")
                    except Exception:
                        pass
                    terminated = True
                    tc_results.append(
                        (False, "N/A", f"<judge error: {exc}>",
                         list(self._log[-20:])))

            file_times[fname] = time.time() - t0

        # --- report per file ----------------------------------------------
        ac_count = 0
        for fname, content, start, end in file_ranges:
            results = tc_results[start:end]
            elapsed = file_times[fname]
            all_ok = all(r[0] for r in results)

            if all_ok:
                ac_count += 1
                _eprint(f"{INFO} {fname}")
                _eprint(f"{INFO} time: {elapsed:.6f} sec")
                _eprint(f"{SUCCESS} AC")
                _eprint()
            else:
                _eprint(f"{INFO} {fname}")
                for idx, (ok, _exp, _out, log) in enumerate(results):
                    if not ok:
                        for direction, msg in log:
                            color = DARK_GRAY if direction == '>' else GRAY
                            _eprint(f"{color}  {direction} {msg}{RESET}")
                _eprint(f"{INFO} time: {elapsed:.6f} sec")
                _eprint(f"{FAILURE} WA")
                _eprint("input:")
                _eprint(content.rstrip())
                _eprint()
                _eprint("output:")
                for r in results:
                    _eprint(r[2])
                _eprint()
                _eprint("expected:")
                for r in results:
                    _eprint(r[1])
                _eprint()

        # --- summary ------------------------------------------------------
        total_files = len(file_ranges)
        if file_times:
            slowest = max(file_times, key=file_times.get)
            _eprint(f"{INFO} slowest: "
                    f"{file_times[slowest]:.6f} sec  (for {slowest})")
        if ac_count == total_files:
            _eprint(f"{SUCCESS} test success: "
                    f"{total_files} cases")
        else:
            _eprint(f"{FAILURE} test failed: "
                    f"{ac_count} AC / {total_files} cases")

        sys.stderr.flush()
        exit_code = 0 if ac_count == total_files else 1
        try:
            sys.stdout.close()
        except Exception:
            pass
        os._exit(exit_code)
