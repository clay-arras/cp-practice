// https://leetcode.com/problems/3sum

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = list()
        n = len(nums)
        nums.sort()
        for i in range(n):
            h = dict()
            for j in range(i):
                if - nums[i] - nums[j] in h:
                    a = [nums[i], nums[j], nums[h[- nums[i] - nums[j]]]]
                    a.sort()
                    ret.append(a)
                h[nums[j]] = j
        return ret
                    
                    
        