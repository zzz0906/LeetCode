class Solution:

    def __init__(self, m: int, n: int):
        self.set0 = set()
        self.set1 = set()
        for i in range(m):
            for j in range(n):
                self.set0.add((i,j))
        self.init = copy.deepcopy(self.set0)
    def flip(self) -> List[int]:
        res = []
        for ele in self.set0:
            res = [ele[0], ele[1]]
            self.set0.remove((ele))
            self.set1.add((ele))     
            break
        return res

    def reset(self) -> None:
        self.set0 = set()
        self.set1 = set()
        self.set0 = self.init
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()