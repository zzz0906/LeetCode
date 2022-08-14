"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def dfs(self, cur: 'Node'):
        if not cur:
            return 0
        if not cur.children:
            return 1
        return max(self.dfs(child) for child in cur.children) + 1
    def maxDepth(self, root: 'Node') -> int:
        return self.dfs(root)