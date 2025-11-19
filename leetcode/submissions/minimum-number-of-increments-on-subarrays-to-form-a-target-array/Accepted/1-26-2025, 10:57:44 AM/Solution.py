// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
            
        if not target:
            return 0
        operations = target[0]
        for i in range(1, len(target)):
            diff = target[i] - target[i-1]
            if diff > 0:
                operations += diff
        return operations
