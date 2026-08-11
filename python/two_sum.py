class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numToInd = {}

        for i, n in enumerate(nums):
            if target - n in numToInd:
                return [i, numToInd[target - n]]
            numToInd[n] = i
