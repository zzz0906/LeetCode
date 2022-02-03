class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if (s == ''):
            return True
        for c in t:
            if (c == s[0]):
                s = s[1:]
            if (s == ''):
                return True
        if (s != ''):
            return False
        return True