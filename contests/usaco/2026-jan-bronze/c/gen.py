import random
from collections import defaultdict


def gen():
    N = random.randint(1, 20)
    K = random.randint(1, 6)
    print(N, K)
    Q = random.randint(1, 8)
    print(Q)

    grid = defaultdict(int)
    for _ in range(Q):
        r, c = random.randint(1, N), random.randint(1, N)
        # val = random.randint()


gen()
