// https://leetcode.com/problems/merge-sorted-array

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        j = 0
        for i in range(len(nums1)):
            if j < len(nums2) and (nums1[i] if nums1[i] else math.inf) > nums2[j]:
                nums1[i], nums2[j] = nums2[j], nums1[i]
                j += (nums2[j] is 0)