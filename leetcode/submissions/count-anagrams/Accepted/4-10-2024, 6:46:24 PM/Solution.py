// https://leetcode.com/problems/count-anagrams

class Solution:

    def countAnagrams(self, s: str) -> int:
        MOD = 10**9 + 7
        words = s.split()

        ans = 1
        for word in words:
            tmp = math.factorial(len(word))
            m = defaultdict(lambda: 0)
            for i in word:
                m[i] += 1
            for k, v in m.items():
                tmp //= math.factorial(v)
            ans = (ans * tmp) % MOD
            # print(m)
            # print(''.join(sorted(word)))
            # print(tmp)
        
        # print(ans)
        return int(ans % MOD)
                
