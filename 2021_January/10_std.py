import bisect
from sortedcontainers import SortedList


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        """O(NlogN) / O(N)"""
        ans = 0
        sorted_insts = SortedList()
        for inst in instructions:  # O(N)
            l = sorted_insts.bisect_left(inst)  # O(logN)
            r = len(sorted_insts) - sorted_insts.bisect(inst) # O(logN)
            ans += min(l, r)
            sorted_insts.add(inst)  # O(logN)
        return ans % (10**9 + 7)