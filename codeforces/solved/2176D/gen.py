import random

t = 5
print(t)

for _ in range(t):
    n = random.randint(3, 4)
    m_target = random.randint(2, min(8, n * (n-1)))
    
    a = [random.randint(1, 20) for _ in range(n)]
    edges = set()
    
    # Plant a Fibonacci sequence so the test is actually useful
    seq_len = random.randint(3, n)
    seq = [random.randint(1, 5), random.randint(1, 5)]
    while len(seq) < seq_len:
        seq.append(seq[-1] + seq[-2])
        
    path = random.sample(range(n), seq_len)
    for i, val in enumerate(seq):
        a[path[i]] = val
        
    for i in range(seq_len - 1):
        edges.add((path[i] + 1, path[i+1] + 1))
        
    # Fill up the rest of the edges
    m = max(m_target, len(edges))
    while len(edges) < m:
        u, v = random.randint(1, n), random.randint(1, n)
        if u != v:
            edges.add((u, v))
            
    edge_list = list(edges)
    random.shuffle(edge_list)
    
    print(f"{n} {m}")
    print(" ".join(map(str, a)))
    for u, v in edge_list:
        print(f"{u} {v}")
