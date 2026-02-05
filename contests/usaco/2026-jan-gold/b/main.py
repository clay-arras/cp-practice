from collections import deque


def solve(arr):
    s = 0
    i = 1
    while i < len(arr):
        x = arr[i]
        j = i
        while j > 0 and arr[j - 1] > x:
            arr[j] = arr[j - 1]
            j -= 1
            s += 1
        arr[j] = x
        i += 1
    return s


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        arr = [int(x) for x in input().split(" ")]
        print(solve(arr))


if __name__ == "__main__":
    main()
