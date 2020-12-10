class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        pre_index = len(nums) - 2
        after_index = len(nums) - 1
        while pre_index >= 0 and nums[pre_index] >= nums[pre_index+1]:
            pre_index -= 1
        if pre_index >= 0:
            while nums[after_index] <= nums[pre_index]:
                after_index -= 1    
            nums[pre_index], nums[after_index] = nums[after_index], nums[pre_index]
        nums[pre_index+1:] = sorted(nums[pre_index+1:])
        
