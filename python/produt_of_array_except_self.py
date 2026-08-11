class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        leftProd = [1] * len(nums)
        rightProd = [1] * len(nums)

        for i in range(1, len(nums)):
            leftProd[i] = leftProd[i - 1] * nums[i - 1]
            rightProd[len(nums) - 1 - i] = rightProd[len(nums) - i] * nums[len(nums) - i]
        return [l * r for l, r in zip(leftProd, rightProd)]
