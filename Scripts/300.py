class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        f = []
        answer = 0
        for i in range(0,len(nums)):
            if (len(f) == 0 or f[len(f)-1] < nums[i]):
                f.append(nums[i])
            else:
                st = 0
                ed = len(f)-1
                while (st <= ed):
                    mid = int((st + ed)/2)
                    if (nums[i] > f[mid]):
                        st = mid+1
                        last = st
                    else:
                        ed = mid-1
                        last = ed
                f[st] = nums[i]
        return len(f)
if __name__ == '__main__':
    solution = Solution()
    print(solution.lengthOfLIS([10,9,2,5,3,4]))
