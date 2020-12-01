class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        i = 0
        answer = 0
        while (i < len(nums)):
            target = nums[i]
            start = 0
            end = len(nums) - 1
            print(1)
            while (start < end):
                mid = int((start + end) / 2)
                if (target < nums[mid]):
                    end = mid
                if (target > nums[mid]):
                    start = mid
                if (target == nums[mid]):
                    break
            while (nums[mid] != target):
                mid = mid + 1
            i = mid
            answer = answer + 1
        return answer
def main():
    solution = Solution()
    print(solution.removeDuplicates([1,1,2]))
if __name__ == '__main__':
    main()
