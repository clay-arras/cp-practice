import random


def gen():
    N = random.randint(1, 6)
    print(N)
    A = []
    for i in range(N):
        A.append(random.randint(1, N))
    print(" ".join(list(map(str, A))))

    M = random.randint(1, 6)
    print(M)
    for i in range(M):
        print(random.randint(1, N), "COW"[random.randint(0, 2)])


gen()
