def solve(A, B, cA, cB, fA) -> None:
    fA -= A
    fA -= cA * (B // cB)
    B = B % cB

    def ok(x) -> bool:
        if fA <= 0:
            return True
        if cA * ((x + B) // cB) < fA:  # case 1
            return False
        if x < fA:  # case 2
            return False

        amt = ((x + B) // cB) * cB - 1
        if (x - (amt - B)) + cA * (amt // cB) < fA:
            return False

        assert cB - 1 >= B
        if x - (cB - 1 - B) < fA:  # edge case 1
            return False

        return True

    left, right = -1, int(1e20) + 1
    while left + 1 != right:
        mid = (left + right) >> 1
        if ok(mid):
            right = mid
        else:
            left = mid
    print(right)

    # for x in range(int(1e5)):
    #     if ok(x):
    #         print(x)
    #         return
    # print(-1)


def main() -> None:
    T = int(input())
    for _ in range(T):
        A, B, cA, cB, fA = list(map(int, input().split(" ")))
        solve(A, B, cA, cB, fA)


if __name__ == "__main__":
    main()
