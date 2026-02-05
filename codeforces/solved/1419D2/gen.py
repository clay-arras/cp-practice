import random


def gen():
    T = 1
    for _ in range(T):
        N = random.randint(1, 12)
        print(N)

        p = []
        for i in range(N):
            p.append(random.randint(1, N))
        print(" ".join(list(map(str, p))))


gen()
