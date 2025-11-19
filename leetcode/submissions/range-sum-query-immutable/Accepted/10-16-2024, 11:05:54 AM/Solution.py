// https://leetcode.com/problems/range-sum-query-immutable

class NumArray:
    def __init__(self, nums: List[int]) -> None:
        self.nums: List[int] = nums
        self.prefix_sum: List[int] = [0 for i in range(len(self.nums) + 1)]

        for i in range(1, len(self.nums) + 1):
            self.prefix_sum[i] = self.prefix_sum[i - 1] + self.nums[i - 1]

    def sumRange(self, left: int, right: int) -> int:
        if left > right:
            raise ValueError(
                "Inputs are invalid, the following inputs must follow left <= right"
            )
        if left < 0 or right > len(self.nums):
            raise IndexError("Inputs are out of bounds")

        return self.prefix_sum[right + 1] - self.prefix_sum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)