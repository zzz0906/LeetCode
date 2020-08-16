class Solution:
    def reverseWords(self, s: str) -> str:
        tmp = s.split(" ")
        res = ""
        for i in range(len(tmp)-1,-1,-1):
            if (tmp[i] == ''):
                continue
            if (i == len(tmp) -1 and tmp[i] == ' '):
                continue
            if (res != "" and res[len(res)-1] == ' ' and tmp[i] == ' '):
                continue
            if (i == 0 and tmp[i] == ' '):
                continue
            res += tmp[i]
            if (i != 0):
                res += " "
        return res
                