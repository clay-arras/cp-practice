// https://leetcode.com/problems/uncommon-words-from-two-sentences

from collections import defaultdict

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        l1 = s1.split()
        l2 = s2.split()
        
        m1 = defaultdict(lambda: 0)
        for i in l1: 
            m1[i] += 1
        
        m2 = defaultdict(lambda: 0)
        for i in l2:
            m2[i] += 1
            
        ans = []
        for i in l1:
            if m1[i] == 1 and m2[i] == 0:
                ans.append(i)

        for i in l2:
            if m2[i] == 1 and m1[i] == 0:
                ans.append(i)
            
        return ans