class Solution:
    wDict: List[str]
    flag: bool
    def dfs(self,current,last):
        if (self.flag):
            return
        if (current == ''):
            if (self.wDict.get(last) != None):
                self.flag = True
                return
            else:
                self.flag = False
                return
        tmp = last + current[:1]
        if (self.wDict.get(last) != None):
            self.dfs(current[1:],'')
            self.dfs(current[1:],tmp)
        else:
            self.dfs(current[1:],tmp)
        if (self.flag):
            return
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.wDict = {}
        for each in wordDict:
            self.wDict[each] = 1
        self.flag = False
        self.dfs(s,'')
        return self.flag