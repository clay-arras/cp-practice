def solve() -> None:
    N, K = map(int, input().split())
    arr = []

    for pw in range(20):
        for i in range((1 << pw), N + 1, (1 << (pw + 1))):
            arr.append(i)
    print(arr[K - 1])


def main() -> None:
    T = int(input())
    for _ in range(T):
        solve()


if __name__ == "__main__":
    main()
