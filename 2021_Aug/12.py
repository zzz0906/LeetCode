class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        resKey = []
        res = []
        for string in strs:
            tmpKey = {}
            for alphabet in string:
                if (alphabet in tmpKey):
                    tmpKey[alphabet] += 1
                else:
                    tmpKey[alphabet] = 1
            if (tmpKey in resKey):
                res[resKey.index(tmpKey)].append(string)
            else:
                resKey.append(tmpKey)
                res.append([string])
        return res
