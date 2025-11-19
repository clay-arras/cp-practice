// https://leetcode.com/problems/odd-even-linked-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # might be able to avoid this with previous initialization
        count = 0
        dummy = head
        while dummy is not None:
            dummy = dummy.next
            count += 1

        if count == 0 or count == 1 or count == 2:
            return head
        
        even_dummy = head.next
        odd_dummy = head
        even_head = head.next
        odd_head = head
        while odd_dummy != None and even_dummy != None:
            if even_dummy.next == None:
                break
            odd_dummy.next = even_dummy.next
            odd_dummy = odd_dummy.next

            if odd_dummy.next == None:
                break
            even_dummy.next = odd_dummy.next
            even_dummy = even_dummy.next
        
        odd_dummy.next = even_head
        even_dummy.next = None
        return head


        