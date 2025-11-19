n, k = map(int, input().split(" "))
s = input()

best_ss = s + s
for r in range(n - 1, 0, -1):
    ss = s[:r] * (((2 * n) // r) + 1)
    if ss <= best_ss:
        best_ss = ss

while len(best_ss) < k:
    best_ss += best_ss

print(best_ss[:k])
