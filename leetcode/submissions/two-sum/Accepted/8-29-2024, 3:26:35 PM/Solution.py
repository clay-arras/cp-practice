// https://leetcode.com/problems/two-sum

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer_dict = {}
        for index, num in enumerate(nums):
            otherindex = answer_dict.get(target - num)
            if otherindex is not None and otherindex != index:
                return [index, otherindex]
            answer_dict[num] = index
            
         