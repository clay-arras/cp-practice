import sys, os

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                '..', '..', '..', 'templates'))
from interactive_runner import InteractiveJudge


class GenokrakenJudge(InteractiveJudge):

    def load_tests(self, file_contents):
        self.cases = []
        counts = []
        for content in file_contents:
            tokens = content.split()
            ptr = 0
            t = int(tokens[ptr]); ptr += 1
            for _ in range(t):
                n = int(tokens[ptr]); ptr += 1
                parents = [0]
                for _ in range(1, n):
                    parents.append(int(tokens[ptr])); ptr += 1
                self.cases.append((n, parents))
            counts.append(t)
        return counts

    def num_test_cases(self):
        return len(self.cases)

    def preamble(self):
        return [str(len(self.cases))]

    def init_test_case(self, idx):
        n, _ = self.cases[idx]
        return [str(n)]

    def query_limit(self, idx):
        n, _ = self.cases[idx]
        return 2 * n - 6

    def handle_query(self, idx, parts):
        a, b = int(parts[1]), int(parts[2])
        _, parents = self.cases[idx]

        def subtree_root(u):
            while parents[u] != 0:
                u = parents[u]
            return u

        return "1" if subtree_root(a) != subtree_root(b) else "0"

    def check_answer(self, idx, parts):
        n, parents = self.cases[idx]
        got = [int(x) for x in parts[1:]]
        expected = parents[1:]
        return (
            got == expected,
            " ".join(map(str, expected)),
            " ".join(map(str, got)),
        )


if __name__ == '__main__':
    GenokrakenJudge().run()
