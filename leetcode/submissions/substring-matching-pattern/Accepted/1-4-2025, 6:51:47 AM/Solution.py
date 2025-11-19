// https://leetcode.com/problems/substring-matching-pattern

class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        parr = p.split('*')
        ok1 = False
        ok2 = False
        i = len(parr[0])
        while i < len(s)+1:
            print(s[i-len(parr[0]):i])
            if (s[i-len(parr[0]):i] == parr[0]) and not ok1:
                ok1 = True
                i += len(parr[1])
            if ok1:
                print(s[i-len(parr[1]):i])
                ok2 |= (s[i-len(parr[1]):i] == parr[1])
            i += 1

        return ok1 and ok2
        
        