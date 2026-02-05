from math import inf


def solve(N, k, Q, arr):
    grid = [[0] * (N + 1) for _ in range(N + 1)]
    ans = [0] * Q
    prev_max = -inf

    for idx, (r, c, v) in enumerate(arr):
        grid[r][c] = v
        A = (max(r - k + 1, 1), max(c - k + 1, 1))
        B = (max(r - k + 1, 1), min(c + k - 1, N))
        C = (min(r + k - 1, N), max(c - k + 1, 1))
        D = (min(r + k - 1, N), min(c + k - 1, N))

        length_r = D[0] - A[0] + 1
        length_c = D[1] - A[1] + 1
        pref = [[0] * (length_c + 1) for _ in range(length_r + 1)]
        for ofr in range(length_r):
            for ofc in range(length_c):
                i, j = A[0] + ofr, A[1] + ofc
                if 1 <= i <= N and 1 <= j <= N:
                    pref[ofr + 1][ofc + 1] = (
                        grid[i][j]
                        + pref[ofr][ofc + 1]
                        + pref[ofr + 1][ofc]
                        - pref[ofr][ofc]
                    )

        for ofr in range(length_r // 2):
            for ofc in range(length_c // 2):
                curr = (
                    pref[ofr + length_r + 1][ofc + length_c + 1]
                    + pref[ofr][ofc]
                    - pref[ofr + length_r + 1][ofc]
                    - pref[ofr][ofc + length_c + 1]
                )
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
