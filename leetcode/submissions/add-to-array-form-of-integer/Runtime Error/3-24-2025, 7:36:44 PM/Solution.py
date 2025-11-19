// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num = int(''.join([str(i) for i in num]))
        num += k
        num = str(num)
        num = [int(i) for i in num]
        return num
        
        
        