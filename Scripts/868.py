class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        mid = N
        flag = False
        now = 0
        start = 0
        end = 0
        answer = 0
        while (mid != 0):
            modnumber = mid % 2
            if (modnumber == 1 and flag == False):
                start = now
                flag = True
                #print(start)
            if (modnumber == 1 and flag == True):
                end = now
                if (end - start > answer):
                    answer = end - start
                start = now
                #print(end)
            mid = int(mid / 2)
            now = now + 1
        return answer
solution = Solution()
print(solution.binaryGap(22))
