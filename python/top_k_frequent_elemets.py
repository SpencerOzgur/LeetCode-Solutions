class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ctr = Counter(nums)
        res = []

        for n, v in reversed(sorted([(key, val) for key, val in ctr.items()], key=lambda x:x[1])):
            res.append(n)
            if len(res) == k:
                return res
