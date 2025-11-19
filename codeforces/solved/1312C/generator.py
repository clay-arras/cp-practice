import random


def gen():
    T = 5
    print(T)
    for _ in range(T):
        N = random.randint(1, 30)
        K = random.randint(2, 100)
        print(N, K)
        a = [None for _ in range(N)]
        for i in range(N):
            # a[i] = random.randint(0, 1e16)
            a[i] = random.randint(0, 1e3)
        print(*[a[i] for i in range(N)])



gen()
