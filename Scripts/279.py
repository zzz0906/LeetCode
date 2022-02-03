import math
class Solution:
    def numSquares(self, n: int) -> int:
        # maxn = int(math.sqrt(n))
        # if (maxn * maxn == n):
        #     return 1
        # ans = 2<<16
        # while (maxn > 0):
        #     tmp = self.numSquares(n-maxn*maxn)
        #     if (tmp + 1 < ans):
        #         ans =  tmp + 1
        #     maxn -= 1
        # return ans
        # let F[i] be the minimum perfect square needed

        INT_MAX = 2<<16
        F = []
        F.append(1)
        F.append(1) #dummy 0
        if (n <= 1):
            return 1
        for i in range(2,n+1):
            maxn = int(math.sqrt(i))
            if (maxn * maxn == i):
                F.append(1)
                continue
            else:
                tmp = INT_MAX
                while (maxn > 0):
                    tmp = min(F[i-maxn*maxn] + 1,tmp)
                    maxn -= 1
                F.append(tmp)
        return F[n]
