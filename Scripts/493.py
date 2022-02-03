class Solution:
    # def checkPalindrome(self, s: str) -> bool:
    #     i = 0
    #     while (i < (len(s) // 2)):
    #         if (s[i] != s[-(i+1)]):
    #             return False
    #         i += 1
    #     return True
    def longestPalindrome(self, s: str) -> int:
        # res = 0
        # for i in range(len(s)):
        #     j = len(s)
        #     while (j > i):
        #         if (self.checkPalindrome(s[i:j])):
        #             break
        #         j -= 1
        #     if (j > i):
        #         res = max(res, j - i)
        # return res
        dic = {}
        res = 0
        for i in range(len(s)):
            if (s[i] in dic):
                dic[s[i]] += 1
            else:
                dic[s[i]] = 1
        odd = False
        for key in dic.keys():
            if (dic[key] % 2 == 0):
                res += dic[key]
            else:
                res += (dic[key] - 1)
                odd = True
        if (odd):
            res += 1
        return res