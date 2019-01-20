class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        First = ['Q','W','E','R','T','Y','U','I','O','P']
        SEC = ['A','S','D','F','G','H','J','K','L']
        LAST= ['Z','X','C','V','B','N','M']
        answer = []
        for word in words:
            now = -1
            answer_flag = True
            for chr in word:
                if (now == - 1):
                    if ((chr.upper()) in First):
                        now = 1
                    if ((chr.upper()) in SEC):
                        now = 2
                    if ((chr.upper()) in LAST):
                        now = 3
                else:
                    flag = False
                    if ((chr.upper()) in First and now == 1):
                        flag = True
                    if ((chr.upper()) in SEC and now == 2):
                        flag = True
                    if ((chr.upper()) in LAST and now == 3):
                        flag = True
                    if (flag == False):
                        answer_flag = False
                        break
            if (answer_flag):
                answer.append(word)
        return answer
