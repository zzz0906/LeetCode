class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if (x > 0):
            data = []
            while (x > 0):
                data.append(x % 10)
                x = x / 10
                print x
        if (x < 0):
            x = x * -1
            return x * -1
        if (x == 0): return x

if __name__ == '__main__':
    solution = Solution()
    print solution.reverse(10)
