import random


def gen():
    N = random.randint(1, 10)
    D = random.randint(1, 10)
    print(N, D)

    prev = 1
    for i in range(N):
        app = random.randint(1, 4)
        prev += app
        print(prev, 1 if random.randint(2, 6) % 3 == 0 else 0)


gen()
