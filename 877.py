class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        f = []
        n = len(piles)
        for i in range(n):
            mid = []
            for j in range(n):
                mid.append(0)
            f.append(mid)
        for i in range(n):
            f[i][i] = piles[i]
        for dis in range(1,n):
            for j in range(0,n-dis):
                f[j][j+dis] = max(piles[j] - f[j+1][j+dis],piles[j+dis]-f[j][j+dis-1])
        return f[0][n-1] > 0
solution = Solution()
solution.stoneGame([1,1,3])
