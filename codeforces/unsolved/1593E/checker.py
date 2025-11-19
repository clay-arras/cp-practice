from collections import deque
t = int(input())
for _ in range(t):
	s=input()
	n,k=map(int,input().split())
	adj=[[] for i in range(n)]
	d=[0]*n
	for i in range(n-1):
		a,b=map(int,input().split())
		adj[a-1].append(b-1)
		adj[b-1].append(a-1)
		d[a-1]+=1
		d[b-1]+=1
	ans=n
	q=deque()
	for i in range(n):
		if d[i]==1:
			q.append(i)
	for p in range(k):
		if len(q)==0 or ans==1:
			ans=0
			break
		for i in range(len(q)):
			t=q.popleft()
			d[t]=0
			ans-=1
			for j in adj[t]:
				d[j]-=1
				if d[j]==1:
					q.append(j)
	print(ans)
