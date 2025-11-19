// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        curr = head
        arr = []
        while curr != None:
            arr.append(curr)
            curr = curr.next
        
        ans = 0
        for i in range(len(arr)//2):
            ans = max(ans, arr[i] + arr[len(arr)//2 - i - 1])
        
        return ans

        