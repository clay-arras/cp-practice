
q=int(input().strip())
for _ in range(q):
 u,v,w=map(int,input().split())
 if v==1:
  print(-1)
 else:
  z=w
  lim=10**12
  for j in range(u):
   add=(z-1)//(v-1)
   z+=add
   if z>lim:
    break
  print(-1 if z>lim else z)
