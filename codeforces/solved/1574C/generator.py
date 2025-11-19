import random


def gen():
    N = random.randint(2, 100)
    print(N)
    a = [None for _ in range(N)]
    for i in range(N):
        a[i] = random.randint(1, 100)
    print(*[a[i] for i in range(N)])

    print(1)
    x = random.randint(1, 200)
    y = random.randint(1, 10000)
    print(x, y)


gen()
