from functools import cache


def solve(carr, parr):
    N = len(carr)
    @cache
    def dp(i, S):
        if i > N - 1:
            return 0
        return max(dp(i + 1, S), dp(i + 1, S * (1 - parr[i] / 100)) + S * carr[i])
    ans = dp(0, 1)
    return ans


def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        parr = []
        carr = []
        for _ in range(n):
            c, p = [int(x) for x in input().split()]
            parr.append(p)
            carr.append(c)
        print(solve(carr, parr))


if __name__ == '__main__':
    main()
