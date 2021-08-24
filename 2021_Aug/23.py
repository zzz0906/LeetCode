# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def findTargetValue(self, root, k):
        if (root == None):
            return None
        
        if (k == root.val):
            return root
        if (k < root.val):
            return self.findTargetValue(root.left, k)
            
        return self.findTargetValue(root.right, k)
        
    
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        stack = []
        stack.append(root)
        
        while (len(stack) > 0):
            head = stack[0]
            stack = stack[1:]
            
            if (head.left != None):
                stack.append(head.left)
            if (head.right != None):
                stack.append(head.right)
            
            tar = self.findTargetValue(root, k - head.val)
            if (tar != None and tar != head):
                return True
            
        return False