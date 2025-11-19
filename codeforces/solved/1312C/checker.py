R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:
 n,k=R();a=*R(),;r=0;s=1
 while s:z=sum(a);a=[x//k for x in a];r|=s>k*z+1;s=z
 print('YNEOS'[r::2])
