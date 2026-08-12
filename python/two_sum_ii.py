class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        charToInd = {}

        for i, n in enumerate(numbers):
            if target - n in charToInd:
                return [charToInd[target - n], i + 1]
            charToInd[n] = i + 1
