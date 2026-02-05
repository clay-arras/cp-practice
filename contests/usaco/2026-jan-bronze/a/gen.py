import random


def gen():
    T = 5
    print(T)
    for _ in range(T):
        a = [0 for i in range(5)]
        for i in range(5):
            # a[i] = random.randint(0, 1e16)
            a[i] = random.randint(1, 10)
        print(*[a[i] for i in range(5)])


gen()
