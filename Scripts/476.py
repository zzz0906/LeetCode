import math
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        answer_list = []
        answer = 0
        mid = num
        while (mid != 1):
            now_mid = mid % 2
            answer_list.append(now_mid)
            mid = math.trunc(mid / 2)
        answer_list.append(mid)
        mid_ffice = 1
        for i in range(len(answer_list)):
            if (answer_list[i] == 0):
                answer = answer + 1*mid_ffice
                mid_ffice = mid_ffice * 2
            else:
                mid_ffice = mid_ffice*2
        return answer
