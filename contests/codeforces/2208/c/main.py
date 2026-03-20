from functools import cache


def solve(N, c, p):
    ans = 0
    for i in range(N - 1, -1, -1):
        ans = max(ans, c[i] + (100 - p[i]) / 100 * ans)

    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

        C = []
        P = []
        for i in range(n):
            c, p = list(map(int, input().split()))
            C.append(c)
            P.append(p)

        print(solve(n, C, P))


if __name__ == "__main__":
    main()
