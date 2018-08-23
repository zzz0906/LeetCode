class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        answer = 0
        minus_flag = False
        multi_mid = 1
        if_can_transfertonum = False
        ed = len(str)
        for i in range(len(str)):
            if (str[i] == ' ' and if_can_transfertonum == False):
                continue
            if (str[i] == '-' and i+1 < len(str) and ord(str[i+1]) >= 48 and ord(str[i+1]) <= 57 and if_can_transfertonum == False):
                continue
            if (str[i] == '+' and i+1 < len(str) and ord(str[i+1]) >= 48 and ord(str[i+1]) <= 57 and if_can_transfertonum == False):
                continue
            if (ord(str[i]) >= 48 and ord(str[i]) <= 57):
                if_can_transfertonum = True
                continue
            if (if_can_transfertonum == True):
                ed = i
                break
            else:
                return 0
        for i in range(len(str)-2,-1,-1):
            if (str[i] == '-' and ord(str[i+1]) >= 48 and ord(str[i+1]) <= 57):
                minus_flag = True
                continue
        for i in range(ed-1,-1,-1):
            if (str[i] == ' '):
                continue
            if (str[i] == '-'):
                continue
            if (str[i] == '+'):
                continue
            if (ord(str[i]) < 48 or ord(str[i]) > 57):
                break;
            answer += multi_mid * (ord(str[i])-48)
            multi_mid *= 10
            if (answer >= 2147483647 and minus_flag == False):
                return 2147483647
            if (answer >= 2147483648 and minus_flag == True):
                return -2147483648
        if (minus_flag == False):
            return answer
        else:
            return -1*answer
if __name__ == '__main__':
        solution = Solution()
        print solution.myAtoi("0-1")
