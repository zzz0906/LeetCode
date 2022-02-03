class Solution:
    def fib(self, n: int) -> int:
        if (n == 0):
            return 0
        if (n == 1):
            return 1
        last = 1
        lastlast = 0
        for i in range(n-1):
            tmp = last
            last += lastlast 
            lastlast = tmp
        return last
