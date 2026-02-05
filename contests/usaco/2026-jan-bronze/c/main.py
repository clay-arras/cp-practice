from math import inf
from collections import defaultdict


def solve(N, K, Q, arr):
    grid = defaultdict(int)
    ans = [0] * Q
    prev_max = -inf

    for idx, (r, c, v) in enumerate(arr):
        r -= 1
        c -= 1
        grid[(r, c)] = v

        dim = 2 * K - 1
        fr = r - (K - 1)
        fc = c - (K - 1)
        pref = [[0] * (dim + 1) for _ in range(dim + 1)]

        for i in range(1, dim + 1):
            for j in range(1, dim + 1):
                pref[i][j] = (
                    grid[(fr + i - 1, fc + j - 1)]
                    + pref[i - 1][j]
                    + pref[i][j - 1]
                    - pref[i - 1][j - 1]
                )

        for i in range(K):
            for j in range(K):
                curr = pref[i + K][j + K] + pref[i][j] - pref[i][j + K] - pref[i + K][j]
                prev_max = max(prev_max, curr)
        ans[idx] = prev_max

    return ans


def main():
    N, K = list(map(int, input().split(" ")))
    Q = int(input())
    arr = [None] * Q
    for i in range(Q):
        arr[i] = tuple(int(x) for x in input().split(" "))
    for row in solve(N, K, Q, arr):
        print(row)


if __name__ == "__main__":
    main()


"""
instead of using prefix sum, create a mapping from top-left coordinate
"""
