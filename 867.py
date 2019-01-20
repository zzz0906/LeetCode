class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        answer =[]
        first_x = len(A)
        first_y = len(A[0])
        for i in range(first_y):
            mid_answer = []
            for j in range(first_x):
                mid_answer.append(0)
            answer.append(mid_answer)
        #print(answer)
        #print(first_x,first_y)
        for i in range(len(A)):
            for j in range(len(A[i])):
                answer[j][i] = A[i][j]
        #print(answer)
        return answer
solution = Solution()
solution.transpose([[1,2,3],[4,5,6]])
