class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        numSet = set(nums)

        for n in numSet:
            if n - 1 in numSet:
                continue
            
            cur = 1
            while n + 1 in numSet:
                cur += 1
                n += 1

            res = max(cur, res)
        return res
