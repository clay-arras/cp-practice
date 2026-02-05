from math import inf
import itertools

MOD = 1e9 + 7


def check_member(x, intv):
    return intv[0] <= x <= intv[1]


def solve(N, D, arr) -> None:
    N = len(arr)
    chs = [y[0] for y in filter(lambda x: x[1] == 1, arr)]

    ans = 0
    for r in range(N + 1):
        for combo in itertools.combinations(chs, r):
            intervals = []
            for c in combo:
                intervals.append((c, c + D))

            pow = 0
            for i in arr:
                if i[1] == 0:
                    pow += any(check_member(i[0], intv) for intv in intervals)

            ans += 2**pow
    print(int((ans - 1) % MOD))


def main() -> None:
    N, D = [int(x) for x in input().split(" ")]
    arr = []
    for _ in range(N):
        p, o = [int(x) for x in input().split(" ")]
        arr.append((p, o))
    solve(N, D, arr)


if __name__ == "__main__":
    main()
