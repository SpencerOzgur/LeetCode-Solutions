# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        carry = 0
        temp = dummy

        while l1 or l2 or carry:
            l1Val = l1.val if l1 else 0
            l2Val = l2.val if l2 else 0

            newDig = (l1Val + l2Val + carry ) % 10
            carry = (l1Val + l2Val + carry ) // 10

            newNode = ListNode(newDig)
            temp.next = newNode
            temp = temp.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return dummy.next


