// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        count = 0
        n = head
        while n != None:
            count += 1
            n = n.next
        
        n = head
        count = floor(count/2)
        for i in range(count - 1):
            n = n.next

        tmp = n.next.next
        n.next = tmp

        return head