// https://leetcode.com/problems/odd-even-linked-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # might be able to avoid this with previous initialization
        if head == None:
            return None

        even_dummy = ListNode(-1, head)
        odd_dummy = ListNode(-1, even_dummy)
        dummy = head.next
        while odd_dummy != None and even_dummy != None:
            if even_dummy.next == None:
                break
            odd_dummy.next = even_dummy.next
            odd_dummy = odd_dummy.next

            if odd_dummy.next == None:
                break
            even_dummy.next = odd_dummy.next
            even_dummy = even_dummy.next
        
        odd_dummy.next = dummy
        even_dummy.next = None
        return head


        