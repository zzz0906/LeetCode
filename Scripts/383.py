class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_dic = {}
        for c in magazine:
            if c in mag_dic:
                mag_dic[c] += 1
            else:
                mag_dic[c] = 1
        for c in ransomNote:
            if (c not in mag_dic):
                return False
            mag_dic[c] -= 1
            if (mag_dic[c] < 0):
                return False
        return True