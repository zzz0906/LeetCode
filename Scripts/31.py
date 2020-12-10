class Solution(object):
    nums = []
    answers = []
    bools = []
    def dfs(self,answer,coefficient,count):
        if (count == len(self.nums)):
            self.answers.append(answer)
        else:
            for i in range(len(self.nums)):
                if (self.bools[i] == True):
                    self.bools[i] = False
                    self.dfs(answer+self.nums[i]*coefficient,coefficient*10,count+1)
                    self.bools[i] = True
    def quick_sort(self,begin,end):
        bbegin = begin
        eend = end
        if (begin >= end):
            return
        base = self.answers[begin]
        while (begin < end):
            while(end > begin and self.answers[end] >= base):
                end = end - 1
            self.answers[begin] = self.answers[end]
            while(begin < end and self.answers[begin] <= base):
                begin = begin + 1
            self.answers[end] = self.answers[begin]
            self.answers[begin] = base
        self.quick_sort(bbegin,begin-1)
        self.quick_sort(end+1,eend)
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        self.nums = nums
        for i in range(len(nums)):
            self.bools.append(True)
        self.dfs(0,1,0)
        coefficient = 1
        real_q = 0
        for i in range(len(nums)-1,-1,-1):
            real_q = real_q + coefficient * nums[i]
            coefficient = coefficient * 10

        self.quick_sort(0,len(self.answers)-1)
        for i in range(len(self.answers)):
            if (self.answers[i] == real_q):
                if (i != len(self.answers)-1):
                    r_answer = self.answers[i+1]
                    answer_nums = []
                    while(r_answer != 0):
                        m_answer = r_answer % 10
                        answer_nums.insert(0,m_answer)
                        r_answer = int(r_answer / 10)
                    nums = answer_nums
                    self.nums = answer_nums
                else:
                    r_answer = self.answers[0]
                    answer_nums = []
                    while(r_answer != 0):
                        m_answer = r_answer % 10
                        answer_nums.insert(0,m_answer)
                        r_answer = int(r_answer / 10)
                    nums = answer_nums
                    self.nums = answer_nums
        nums = self.nums
solution = Solution()
print(solution.nextPermutation([1,2,3]))
