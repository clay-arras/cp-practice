// https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        cc = Counter(s)
        cnt = OrderedDict(sorted(cc.items()))
        # for c in s:
        #     cnt[c] += 1

        odds = []
        for k, v in cnt.items():
            if v % 2 == 1:
                odds.append(k)
        print(cnt, odds)
        if len(odds) > 1:
            return ""

        for k in [i for i in cnt]:
            cnt[k] //= 2

        # @cache
        def full(val):
            if len(s) % 2 == 0:
                return val + val[::-1]
            else:
                print(odds)
                return val + odds[0] + val[::-1]

        ans = ""
        
        @cache
        def dfs(pref, bigger):
            nonlocal ans
            if 2*len(pref) + len(odds) == len(target) and (f := full(pref)) > target:
                ans = min(ans, f) if ans != "" else f
                return
                
            if pref < target[:len(pref)]:
                return

            if bigger:
                rr = ""
                for k, v in cnt.items():
                    for _ in range(v):
                        rr += k
                print(pref + rr)
                f = full(pref + rr)
                if f > target:
                    ans = min(ans, f) if ans != "" else f
                    return
            

            for k in cnt:
                if cnt[k] <= 0 or (not bigger and k < target[len(pref)]):
                    continue
                
                cnt[k] -= 1
                if (k > target[len(pref)]):
                    dfs(pref + k, True)
                else:
                    dfs(pref + k, bigger)
                cnt[k] += 1

        dfs("", False)
        dfs.cache_clear()
        return ans if ans > target else ""
