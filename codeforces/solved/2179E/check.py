t=int(input())
for _ in range(t):
    n,x,y=map(int,input().split())
    s=input().strip()
    p=list(map(int,input().split()))
    cnt=0
    a=0
    b=0
    total=sum(p)
    if total > x + y:
        print("NO")
        continue
 
    for i in range(n):
        if s[i]=='0':
            cnt += 1
            a+=p[i] // 2 + 1
        else:
            b+=p[i] // 2 + 1
    if  x>=a and y>=b:
        if (cnt == n and x - y < n) or (cnt == 0 and y - x < n):
            print("NO")
        else :
            print("YES")
    else:
        print("NO")
