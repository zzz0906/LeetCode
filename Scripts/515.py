class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def helper(root, depth):
            if root is None:
                return
            
            if depth == len(res):
                res.append(root.val)
            else:
                res[depth] = max(res[depth], root.val)
            
            helper(root.left, depth + 1)
            helper(root.right, depth + 1)
        
        helper(root, 0)
        
        return res