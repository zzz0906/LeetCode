class Solution:
    def dfs(i):
        if (i == len(strl) and self.stack == 0):
            self.answer = self.answer + 1
            return
        if (self.strl[i] == '('):
            self.stack = self.stack + 1
        else:
            dfs(i+1)
            self.stack = self.stack - 1
            dfs(i+1)
            self.stack = self.stack + 1
    def longestValidParentheses(self, s: str) -> int:
        self.strl = s
        dfs(0)
            