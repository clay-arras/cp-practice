n = int(input())
l = sorted(map(int, input().split()))
b = [0] * n
b[1::2] = l[: n // 2]
b[::2] = l[n // 2 :]
print(sum(b[i] > b[i + 1] < b[i + 2] for i in range(n - 2)))
# print(*b)
