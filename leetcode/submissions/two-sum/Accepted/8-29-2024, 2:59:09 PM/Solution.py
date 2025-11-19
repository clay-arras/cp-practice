// https://leetcode.com/problems/two-sum

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for index, num in enumerate(nums):
            for otherindex in range(index, len(nums)):
                othernum = nums[otherindex]
                # print([num, othernum, index, otherindex])
                if num + othernum == target and index != otherindex:
                    return [index, otherindex]
         