class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(0,int(math.sqrt(c//2)) + 2):
            print(i)
            if c - i*i >= 0 and int(sqrt((c - i*i)))**2 == c - i*i:
                return True
        return False