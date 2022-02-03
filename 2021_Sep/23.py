class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        """
        :type palindrome: str
        :rtype: str
        """
        for i in range(len(palindrome)):
            if palindrome[i] == 'a':
                continue
            if (i == int(len(palindrome) / 2)):
                continue
            
            return palindrome[:i] + 'a' + palindrome[i+1:]
        
        if len(palindrome) == 1:
            return ''
        
        elif palindrome[-1] == 'a': # xxxxa
            return palindrome[:-1] + 'b'
        
        return '' #inpossible