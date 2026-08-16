class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = r

        while l <= r:
            mid = l + (r - l) // 2
            if sum([ceil(p / mid) for p in piles]) <= h:
                res = min(res, mid)
                r = mid - 1
            else:
                l = mid + 1
        return res
