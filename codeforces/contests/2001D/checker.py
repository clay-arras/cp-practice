from collections import Counter

t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    num = list(map(int,input().split()))
    cnt = Counter(num)

    ans = []
    sign = lambda x:-1 if x % 2 == 0 else 1
    s = set()

    for i in num:
        if i not in s:
            while True:
                if len(ans) >= 2 and sign(len(ans)-2) * i < sign(len(ans)-2) * ans[-2] and cnt[ans[-2]] > 0 and cnt[ans[-1]] > 0:
                    s.remove(ans[-2])
                    s.remove(ans[-1])
                    ans.pop()
                    ans.pop()
                elif len(ans) >=1 and sign(len(ans)-1) * i < sign(len(ans)-1) * ans[-1] and cnt[ans[-1]] > 0:
                    s.remove(ans[-1])
                    ans.pop()
                else:
                    break
            s.add(i)
            ans.append(i)
        cnt[i] -= 1

    print(len(ans))
    print(*ans)

