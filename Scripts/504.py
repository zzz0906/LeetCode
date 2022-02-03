class Solution:
    def convertToBase7(self, num: int) -> str:
        # 100 % 7 = 2
        # 100 / 7 = 14
        # 14 % 7 = 0
        # 14 / 7 = 2
        # 2 % 7 = 2
        # 2 / 7 = 0
        if (num == 0):
            return '0'
        res = ""
        flag = False
        if (num < 0):
            flag = True
            num *= -1
        while (num > 0):
            remaind = num % 7
            # print(remaind)
            res += str(remaind)
            num = num // 7
        res = res[::-1]
        if (flag):
            res = '-' + res
        return res