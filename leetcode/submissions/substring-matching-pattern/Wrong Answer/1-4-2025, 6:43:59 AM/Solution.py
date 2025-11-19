// https://leetcode.com/problems/substring-matching-pattern

class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        parr = p.split('*')
        ok1 = False
        ok2 = False
        for i in range(len(parr[0]), len(s)+1):
            ok1 |= (s[i-len(parr[0]):i] == parr[0])
            # print(s[i-len(parr[0]):i])
            i += len(parr[0])
            if ok1:
                # print(s[i-len(parr[1]):i])
                ok2 |= (s[i-len(parr[1]):i] == parr[1])

        return ok1 and ok2
        
        