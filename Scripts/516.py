class Solution:
    def search(self,s: str) -> int:
        
        for left in range(0, len(s)):
            for right in range(len(s) - 1, left, -1):
                if (s[left] == s[right]):
                    tmp = self.search(s[left + 1:right])
                    self.memory[left , right] = tmp + 1
                    self.res = max(self.res, tmp + 1)
    def longestPalindromeSubseq(self, s: str) -> int:
        self.memory = {}

