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
        for i in range(A[0], C[0] - k + 2):
            for j in range(A[1], B[1] - k + 2):
                curr = 0
                for oi in range(k):
                    for oj in range(k):
                        x = i + oi
                        y = j + oj
                        curr += grid[x][y]
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
