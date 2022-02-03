class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        if (sum(machines) % len(machines) != 0):
            return -1
        even = int(sum(machines) / len(machines))
        diff = 0
        res = 0

        for machine in machines:
            diff += machine - even
            res = max(res, abs(diff))
            res = max(res, machine - even)
        
        return res