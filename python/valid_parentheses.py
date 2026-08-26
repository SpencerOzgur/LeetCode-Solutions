class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        charMap = {
            ')':'(',
            ']':'[',
            '}':'{'
        }

        for c in s:
            if c in charMap and (not stack or stack[-1] != charMap[c]):
                return False
            elif c in charMap:
                stack.pop()
            else:
                stack.append(c)
        return not stack
            
