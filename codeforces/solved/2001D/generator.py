import random


def gen():
    N = random.randint(1, 25)
    print(N)
    a = [None for _ in range(N)]
    for i in range(N):
        a[i] = random.randint(1, 25)
    print(*[a[i] for i in range(N)])


# cases = 100
# print(cases)
# for j in range(cases):
#     gen()
print(1)
gen()
