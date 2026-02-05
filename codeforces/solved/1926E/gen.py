import random


T = 4
print(T)

for _ in range(T):
    N = random.randint(1, 30)
    print(N, random.randint(1, N))
