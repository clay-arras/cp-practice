MOD = 998244353
for _ in range(int(input())):
    n, m = map(int,input().split())
    a = list(map(int,input().split()))
    g = [tuple(map(int,input().split())) for _ in range(m)]
    m = [{} for _ in range(n+1)]
    count = 0
    for u, v in sorted(g,key=lambda x: a[x[1]-1]):
        cur = 1
        if a[v-1] > a[u-1] and (a[v-1]-a[u-1]) in m[u]:
            cur += m[u][a[v-1]-a[u-1]]
            cur %= MOD
        count += cur
        count %= MOD
        m[v][a[u-1]] = cur + m[v].get(a[u-1],0)
        m[v][a[u-1]] %= MOD
    print(count)

