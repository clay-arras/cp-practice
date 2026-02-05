import random

n = random.randint(2, 14)
max_cuts = min(n - 1, 5)
m = random.randint(1, max_cuts)
cuts = random.sample(range(1, n), m)

print(n, m)
print(*cuts)

