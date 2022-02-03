# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, cur, low, high):
        # recursive to a none nodes
        if (cur == None):
            return 0
        # accumulate left and right
        acc_val = self.dfs(cur.left) + self.dfs(cur.right)
        # in the range
        if (cur.val >= low and cur.val <= high):
            acc_val += cur.val
        # return
        return acc_val
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        return self.dfs(root,low,high)