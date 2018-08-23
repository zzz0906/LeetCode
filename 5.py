class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        answer = ""
        if (len(s) == 1):
            return s
        for i in range(len(s)-1):
            mid_answer_1 = s[i]
            st = i - 1
            ed = i + 1
            while st >= 0 and ed <= len(s)-1:
                    if (cmp(s[st],s[ed]) == 0):
                        mid_answer_1 = s[st] + mid_answer_1 + s[ed]
                    else:
                        break
                    st = st - 1
                    ed = ed + 1
            if (s[i] == s[i+1]):
                mid_answer_2 = s[i] + s[i+1]
                st = i - 1
                ed = i + 1 + 1
                while st >= 0 and ed <= len(s)-1:
                        if (s[st] == s[ed]):
                            mid_answer_2 = s[st] + mid_answer_2 + s[ed]
                        else:
                            break
                        st = st - 1
                        ed = ed + 1
                if (len(mid_answer_2) > len(answer)):
                    answer = mid_answer_2
            if (len(mid_answer_1) > len(answer)):
                answer = mid_answer_1
        return answer
if __name__ == '__main__':
    s = Solution()
    print(s.longestPalindrome("abcda"))
