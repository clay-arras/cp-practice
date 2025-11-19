// https://leetcode.com/problems/substring-matching-pattern

class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        parr = p.split('*')
        ok1 = False
        ok2 = False
        for i in range(len(parr[0]), len(s)):
            ok1 |= (s[i-len(parr[0]):i] == parr[0])
            i += 1
            if ok1:
                ok2 |= (s[i-len(parr[1]):i] == parr[1])

        return ok1 and ok2
        
        