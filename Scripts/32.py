class Solution:
    strl = ""
    answer = 0
    stack = 0
    def dfs(self,i):
        if (i == len(self.strl) and self.stack == 0):
            self.answer = self.answer + 1
            return
        if (i == len(self.strl)):
            return
        if (self.strl[i] == '('):
            self.dfs(i+1)
            self.stack = self.stack + 1
            self.dfs(i+1)
            self.stack = self.stack - 1
            return
        else:
            self.dfs(i+1)
            self.stack = self.stack - 1
            self.dfs(i+1)
            self.stack = self.stack + 1
    def longestValidParentheses(self, s: str) -> int:
        self.strl = s
        self.answer = 0
        self.dfs(0)
        return self.answer -1
            