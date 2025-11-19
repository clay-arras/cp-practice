from bisect import*
n=int(input())
a,b=[],[]
for _ in[0]*n:
    l,*s=map(int,input().split())
 if s[::-1]==sorted(s):insort(a,s[0]);b+=s[-1],
print(n*n-sum(bisect(a,x)for x in b))
