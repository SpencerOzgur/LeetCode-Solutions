# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        N = 0
        temp = head
        while temp:
            N += 1
            temp = temp.next
        
        if N == n:
            return head.next
        
        temp = head
        i = 0
        while temp:
            if i == N - n - 1:
                temp.next = temp.next.next
                return head
            temp = temp.next
            i += 1
