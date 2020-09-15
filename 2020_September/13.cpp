class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s == '':
            return 0
        a = s.split(' ')
        while (len(a) > 0 and a[-1] == ''):
            a.pop(-1)
        if (len(a) == 0):
            return 0
        return len(a[-1])
        