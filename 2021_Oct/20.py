class Solution:
    def reverseWords(self, s: str) -> str:
        
        s=s.strip()
        list_of_words=s.split()
        
        return (" ".join(list_of_words[::-1]))       