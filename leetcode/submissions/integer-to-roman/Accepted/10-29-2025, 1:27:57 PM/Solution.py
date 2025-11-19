// https://leetcode.com/problems/integer-to-roman

class Solution:
    def intToRoman(self, num: int) -> str:
        pows = [
            {1: "I", 4: "IV", 5: "V", 9: "IX"},
            {1: "X", 4: "XL", 5: "L", 9: "XC"},
            {1: "C", 4: "CD", 5: "D", 9: "CM"},
            {1: "M"}
        ]

        i = 0
        ans = []
        for c in reversed(str(num)):
            d = int(c) 
            tmp = []
            for k in sorted(pows[min(len(pows) - 1, i)].keys(), reverse=True):
                while d >= k:
                    d -= k
                    tmp.append(pows[i][k])
            ans.extend(reversed(tmp))
            i += 1

        return "".join(reversed(ans))