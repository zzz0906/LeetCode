class Solution:
    def frequencySort(self, s: str) -> str:
        d = {}
        for c in s:
            if c not in d:
                d[c] = 1
            else:
                d[c] += 1
        res = ""
        a = sorted(d.items(), key=lambda x: x[1], reverse=True)
        for k,v in a:
            res += k*v
        return res