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
        if n == N:
            return head.next

        i = 0
        temp = head
        while True:
            if i == N - n - 1:
                temp.next = temp.next.next
                return head
            i += 1
            temp = temp.next
        
