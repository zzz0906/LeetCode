# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, cur, height):
        # node is none
        if (cur == None):
            return
        # update maximum height
        if (height > self.maxH):
            self.maxH = height
        # the fisrt node in a height level == left most node
        if (height not in self.dic):
            self.dic[height] = cur.val
        self.dfs(cur.left,height + 1)
        self.dfs(cur.right,height + 1)
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.dic = {}
        self.maxH = 0
        self.dfs(root, 1)
        return self.dic[self.maxH]