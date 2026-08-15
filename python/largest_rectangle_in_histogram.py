class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        res = 0

        for i, h in enumerate(heights):
            begin = i
            while stack and stack[-1][0] > h:
                res = max(res, (i - stack[-1][1]) * stack[-1][0])
                begin = stack[-1][1]
                stack.pop()
            stack.append((h, begin))
        
        print(stack)
        while stack:
            res = max(res, (len(heights) - stack[-1][1])*stack[-1][0])
            stack.pop()
        return res
