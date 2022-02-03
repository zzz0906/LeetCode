class Solution:
    wDict: List[str]
    flag: bool
    def dfs(self,current,last,tmpanswer):
        if (current == ''):
            if (last == ''):
                self.answer.append(tmpanswer)
                return
            else:
                return
        tmp = last + current[:1]
        if (self.wDict.get(tmp) != None):
            self.dfs(current[1:],tmp,tmpanswer)
            if (tmpanswer != ''):
                tmpanswer += ' '
            self.dfs(current[1:],'',tmpanswer+tmp)
        else:
            self.dfs(current[1:],tmp,tmpanswer)
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        self.wDict = {}
        for each in wordDict:
            self.wDict[each] = 1
        self.answer: List[str]
        self.answer = []
        self.dfs(s,'','')
        return self.answer