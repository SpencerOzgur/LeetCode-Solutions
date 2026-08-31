# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        cur = head.next
        prev = head
        stack = []
        i = 1
        minDist = float('inf')

        while cur and cur.next:
            if ((cur.val > cur.next.val and cur.val > prev.val) or
                (cur.val < cur.next.val and cur.val < prev.val)):
                if stack and minDist > i - stack[-1]:
                    minDist = i - stack[-1]
                stack.append(i)
            i += 1
            prev = cur
            cur = cur.next
        return [minDist, stack[-1] - stack[0]] if len(stack) > 1 else [-1, -1]
