from itertools import pairwise
from math import inf

def min_cost(n, cuts):
    nc = len(cuts)
    segs = []
    ret = 0
    endpoints = [0] + list(sorted(cuts)) + [n]
    for x, y in pairwise(endpoints):
        segs.append((x, y))

    for _ in range(nc):
        mcost = inf
        start, end, mid = None, None, None
        for i, (x1, x2) in enumerate(pairwise(segs)):
            cost = x2[1] - x1[0]
            if cost < mcost:
                mid = i
                mcost = cost
                start, end = x1[0], x2[1]
        segs.pop(mid + 1)
        segs.pop(mid)
        segs.insert(mid, (start, end))
        ret += mcost
    return ret

n, m = map(int, input().split())
cuts = list(map(int, input().split()))
print(min_cost(n, cuts))
