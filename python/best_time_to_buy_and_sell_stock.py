class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        smallest = prices[0]

        for p in prices:
            res = max(res, p - smallest)
            smallest = min(smallest, p)
        return res
