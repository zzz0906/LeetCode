# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, lastV):
        leftNum = 0
        rightNum = 0
        if (root.left):
            leftNum = self.dfs(root.left, root.val)
        if (root.right):
            rightNum = self.dfs(root.right, root.val)
        if (1 + leftNum + rightNum) > self.count:
            self.count = 1 + leftNum + rightNum
            self.res = [root.val]
        else:
            if (1 + leftNum + rightNum) == self.count:
                self.res.append(root.val)
        
        if (root.val == lastV):
            return (1 + leftNum + rightNum)
        else:
            return 0
        
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.res = []
        self.count = 0
        self.dfs(root, root.val)
        return self.res