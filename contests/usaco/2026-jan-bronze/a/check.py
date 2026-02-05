def solve(A, B, cA, cB, fA) -> None:
    def ok(x) -> bool:
        for a in range(0, x + 1):
            aes = a + A
            bes = (x - a) + B
            if aes + cA * (bes // cB) < fA:
                return False
        return True

    for x in range(int(1e5)):
        if ok(x):
            print(x)
            return
    print(-1)


def main() -> None:
    T = int(input())
    for _ in range(T):
        A, B, cA, cB, fA = list(map(int, input().split(" ")))
        solve(A, B, cA, cB, fA)


if __name__ == "__main__":
    main()
