// https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        cnt = defaultdict(lambda: 0)
        for c in s:
            cnt[c] += 1

        odds = []
        for k, v in cnt.items():
            if v % 2 == 1:
                odds.append(k)
        if len(odds) > 1:
            return ""

        for k in [i for i in cnt]:
            cnt[k] //= 2

        def full(val):
            if len(s) % 2 == 0:
                return val + val[::-1]
            else:
                return val + odds[0] + val[::-1]

        ans = ""

        @cache
        def dfs(i, pref):
            nonlocal ans
            if len(full(pref)) == len(target) and full(pref) > target:
                ans = full(pref)
                return True

            for k in cnt:
                if cnt[k] <= 0 or pref + k < target[:len(pref) + 1]:
                    continue
                
                cnt[k] -= 1
                ok = dfs(i+1, pref + k)
                if ok: return True
                cnt[k] += 1
                
            return False

        dfs(0, "")
        return ans if ans > target else ""
