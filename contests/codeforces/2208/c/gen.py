import random


def gen():
    T = 10
    print(T)
    for _ in range(T):
        N = random.randint(1, 100)
        # N = random.randint(1, 8)
        print(N)

        for i in range(N):
            # print(random.randint(1, 20), 20 * random.randint(0, 5))
            print(random.randint(1, 100), random.randint(0, 100))


gen()
