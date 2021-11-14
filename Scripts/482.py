class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        ss = s.split('-')
        all = ''
        for single in ss:
            all += single
        if (all == ''):
            return ''
        first = all[:len(all) % k]
        all = all[len(all) % k:]
        res = first.upper()
        if (len(res) != 0):
            res += '-'
        for i in range(0, len(all)):
            if (i != 0 and i % k == 0):
                res += '-'
            res += all[i].upper()
        if (res[-1] == '-'):
            return res[:-1]
        return res