// https://leetcode.com/problems/count-and-say

class Solution:
    def runLengthEncode(self, s: str) -> str:
        ans = ""
        count = 1
        for i in range(len(s)-1):
            if s[i+1] == s[i]:
                count += 1
            else: 
                ans += str(count) + str(s[i])
                count = 1
        ans += str(count) + str(s[len(s)-1])
        return ans

    def countAndSay(self, n: int) -> str:
        ans = "1"
        for i in range(n-1):
            ans = self.runLengthEncode(ans)
        
        return ans

        