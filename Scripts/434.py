class Solution:
    def countSegments(self, s: str) -> int:
        return len(list(filter(None, s.split(" "))))