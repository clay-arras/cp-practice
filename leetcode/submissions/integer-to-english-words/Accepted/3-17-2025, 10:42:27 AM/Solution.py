// https://leetcode.com/problems/integer-to-english-words

class Solution:
    def __init__(self) -> None:
        self.ones = ["ERROR", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        self.tens = ["ERROR", "ERROR", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        self.spc_tens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        self.thsd = ["ERROR", "Thousand", "Million", "Billion"]

    def getDigit(self, num: int, i: int) -> int:
        """
        example: 123
        0th digit -> 1
        1st digit -> 2
        3rd digit -> 0
        """
        str_num = str(num)[::-1] + i*"0"
        return int(str_num[i])

    def processThousand(self, num: int) -> str:
        one = self.getDigit(num, 0)
        ten = self.getDigit(num, 1)
        hun = self.getDigit(num, 2)

        str_list = []
        if hun != 0:
            str_list.append(self.ones[hun])
            str_list.append("Hundred")
        
        if ten != 0 and ten == 1:
            str_list.append(self.spc_tens[one])
        if ten != 0 and ten != 1:
            str_list.append(self.tens[ten])

        if ten != 1 and one != 0:
            str_list.append(self.ones[one])
        
        return " ".join(str_list)

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        ans = []
        size = ceil(len(str(num))*1.0/3)
        for i in range(size): 
            thsd_str = ""
            thsd_num = int(num % 1000)
            thsd_str += self.processThousand(thsd_num)
            num = int(num/1000)
            if thsd_str == "":
                continue
            if i != 0:
                thsd_str += " " + self.thsd[i]
            ans.append(thsd_str)

        ans = ans[::-1]
        if len(ans) == 0:
            return ans[0]
        return " ".join(ans)
