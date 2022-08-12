class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        words = [word[::-1] for word in words if word != '']
        return ' '.join(words)

s = Solution()
print(s.reverseWords("Let's take LeetCode contest"))