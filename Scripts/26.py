class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        i = 0
        answer = 0
        while (i < len(nums)):
            while (i + 1 < len(nums) and nums[i] == nums[i+1]):
                i = i + 1
            answer = answer + 1
            i =i + 1
        i = 0
        while (i < len(nums)):
            justbegin = i
            while (i + 1 < len(nums) and nums[i] == nums[i+1]):
                del nums[i+1]
            i = i + 1
        print(nums)
        return answer
solution = Solution()
print(solution.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))
