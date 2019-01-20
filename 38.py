class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if (n <= 0):
            return " "
        answer = "1"
        for i in range(n-1):
            mid = ""
            j = 0
            while (j < len(answer)):
                count = 1
                while (j + 1 < len(answer) and answer[j] == answer[j+1]):
                    count = count + 1
                    j = j + 1
                    #print(j)
                #print(j)
                mid = mid + str(count) + answer[j]
                j = j + 1
            answer = mid
            #print(answer)
        return answer

solution = Solution()
print(solution.countAndSay(3))
