class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = 0
        length = len(nums)
        while index < length:
            if (nums[index] == 0):
                after = index + 1
                while (after < length and nums[after] == 0):
                    after += 1
                tmp = nums[after]
                nums[after] = 0
                nums[index] = tmp
            index += 1
        
