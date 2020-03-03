class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if (x > pow (2,31) - 1 or x < -pow(2,31)):
            return 0
        answer = 0
        if (x >= 0):
            data = []
            while (x > 0):
                data.append(x % 10)
                x = int(x / 10)
            mid = 1
            while (len(data) != 0):
                answer += data.pop() * mid
                mid = mid * 10
            if (answer > pow (2,31) - 1 or answer < -pow(2,31)):
                return 0
            return answer
        if (x < 0):
            x = x * -1
            data = []
            while (x > 0):
                data.append(x % 10)
                x = int(x / 10)
            mid = 1
            while (len(data) != 0):
                #print(data)
                answer += data.pop() * mid
                mid = mid * 10
            if (answer > pow (2,31) - 1 or answer < -pow(2,31)):
                return 0
            return answer * -1

if __name__ == '__main__':
    solution = Solution()
    print(solution.reverse(-16))
