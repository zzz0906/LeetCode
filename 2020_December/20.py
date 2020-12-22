class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        record = ''
        ans = ''
        index = 0
        while index < len(S):
            if (S[index] >= '0' and S[index] <= '9'):
                num = ''
                num += S[index]
                while (index + 1 < len(S) and S[index + 1] >= '0' and S[index + 1] <= '9'):
                    index += 1
                    num += S[index]
                if (len(num) > 10):
                    num = '1294967296'
                ans += int(num)*record
                record = ''
            else:
                record += S[index]
            index += 1
        ans += record
        return ans[K-1]
