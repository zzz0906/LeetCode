# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from optparse import Option


class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.tilt = 0

        def findTilt(root: Optional[TreeNode]) -> int:
            if not root:
                return 0
            left = findTilt(root.left)
            right = findTilt(root.right)
            self.tilt += abs(left - right)
            return root.val + left + right

        findTilt(root)
        
        return self.tilt