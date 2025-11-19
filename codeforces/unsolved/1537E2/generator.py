import random

m = ['a',
     'b',
     'c',
     'd',
     'e',
     'f',
     'g',
     'h',
     'i',
     'j',
     'k',
     'l',
     'm',
     'n',
     'o',
     'p',
     'q',
     'r',
     's',
     't',
     'u',
     'v',
     'w',
     'x',
     'y',
     'z']

def gen():
    N, K = random.randint(1, 100), random.randint(1, 100)
    print(N, K)

    a = [None for _ in range(N)]
    for i in range(N):
        a[i] = random.randint(0, 25)
    a = [m[i] for i in a]
    print(''.join(a))


gen()
