class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(1, int(len(s) / 2) + 1):
            subs = s[0:i]
            flag = True
            for index in range(0 + i, len(s), i):
                if (subs != s[index : index + i]):
                    flag = False
                    break
            if (flag):
                return True
        return False