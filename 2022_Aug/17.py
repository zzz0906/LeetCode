class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        count = set()
        transfer = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        for word in words:
            count.add("".join([transfer[ord(c)-ord('a')] for c in word]))
        return len(count)

        