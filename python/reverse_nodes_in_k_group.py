# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            kth = self.getKth(groupPrev, k)
            if not kth:
                break
            
            groupNext = kth.next
            prev, cur = groupNext, groupPrev.next

            while cur != groupNext:
                nxt = cur.next
                cur.next = prev
                prev = cur
                cur = nxt
            temp = groupPrev.next
            groupPrev.next = prev
            groupPrev = temp
        return dummy.next

    def getKth(self, cur, k):
        temp = cur
        while temp:
            if not k:
                return temp
            k -= 1
            temp = temp.next
        return None
