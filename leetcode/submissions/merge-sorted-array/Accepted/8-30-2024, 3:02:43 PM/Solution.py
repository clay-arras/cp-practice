// https://leetcode.com/problems/merge-sorted-array

from collections import deque
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        for i in range(m, n+m):
            if nums1[i] == 0:
                nums1[i] = math.inf
        dq = deque()

        j = 0
        for i in range(n+m):
            print(nums1, nums2, dq)
            print(i, j)
            if j < n and nums1[i] > nums2[j] and (len(dq) == 0 or dq[0] >= nums2[j]):
                dq.append(nums1[i])
                nums1[i] = nums2[j]
                j += 1
            elif len(dq) > 0 and nums1[i] > dq[0] and (j >= n or nums2[j] > dq[0]):
                dq.append(nums1[i])
                nums1[i] = dq[0]
                dq.popleft()
        


