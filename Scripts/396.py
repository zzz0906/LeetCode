class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        sums = sum(nums)
        index = 0
        res = 0
        for ele in nums:
            res += index*ele
            index += 1
        ans = res
        for i in range(1,len(nums)):
            res = res + sums - (len(nums))*nums[len(nums) - i]
            ans = max(res,ans)
        return ans