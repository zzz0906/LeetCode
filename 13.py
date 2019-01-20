class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        answer = 0
        while i < len(s):
            flag = False
            if (s[i] == 'I' and i + 1 < len(s) and (s[i+1] == 'V' or s[i+1] == 'X')):
                if (s[i+1] == 'V'):
                    answer = answer + 4
                if (s[i+1] == 'X'):
                    answer = answer + 9
                i = i + 1
                flag = True
            if (s[i] == 'X' and i + 1 < len(s) and (s[i+1] == 'L' or s[i+1] == 'C')):
                if (s[i+1] == 'L'):
                    answer = answer + 40
                if (s[i+1] == 'C'):
                    answer = answer + 90
                i = i + 1
                flag = True
            if (s[i] == 'C' and i + 1 < len(s) and (s[i+1] == 'D' or s[i+1] == 'M')):
                if (s[i+1] == 'D'):
                    answer = answer + 400
                if (s[i+1] == 'M'):
                    answer = answer + 900
                i = i + 1
                flag = True
            if (s[i] == 'I' and flag == False):
                answer = answer + 1
            if (s[i] == 'V' and flag == False):
                 answer = answer + 5
            if (s[i] == 'X' and flag == False):
                answer = answer + 10
            if (s[i] == 'L' and flag == False):
                answer = answer + 50
            if (s[i] == 'C' and flag == False):
                answer = answer + 100
            if (s[i] == 'D' and flag == False):
                answer = answer + 500
            if (s[i] == 'M' and flag == False):
                answer = answer + 1000
            i = i  + 1
        return answer
solution = Solution()
print(solution.romanToInt("IV"))
