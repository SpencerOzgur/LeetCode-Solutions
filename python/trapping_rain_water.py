class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        maxL, maxR = height[l], height[r]
        res = 0

        while l < r:
            if height[l] <= height[r]:
                l += 1
                res += max(0, min(maxL, maxR) - height[l])
                maxL = max(maxL, height[l])
            else:
                r -= 1
                res += max(0, min(maxL, maxR) - height[r])
                maxR = max(maxR, height[r])
        return res
