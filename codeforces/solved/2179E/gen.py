import random


def gen():
    T = 5
    print(T)
    for _ in range(T):
        N = random.randint(1, 10)
        X = random.randint(1, 30)
        Y = random.randint(1, 30)
        print(N, X, Y)

        s = ""
        for i in range(N):
            app = "0" if random.randint(1, 3) % 2 else "1"
            s += app
        print(s)

        p = []
        for i in range(N):
            p.append(random.randint(1, 8))
        print(" ".join(list(map(str, p))))


gen()
