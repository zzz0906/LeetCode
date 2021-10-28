class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        middle = 0
        if (len(nums) == 1):
            return 0
        if (len(nums) % 2 != 0):
            middle = nums[int(len(nums)/2)]
        else:
            middle = int((nums[int(len(nums)/2)] + nums[int(len(nums)/2) - 1])/2)
        res = 0
        for num in nums:
            res += abs(num-middle)
        return res