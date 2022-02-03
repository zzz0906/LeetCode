# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import Counter
class Solution:
    def dfs(self, root):
        # null
        if (not root):
            return 0
        # substree sum
        summ = self.dfs(root.left) + self.dfs(root.right) + root.val
        # not in the dict
        if (summ not in self.dic):
            self.dic[summ] = 1
        # in the dict
        else:
            self.dic[summ] += 1
        # return current sum
        return summ
    
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        # init dict
        self.dic = {}
        # calc sum
        self.dfs(root)

        # sort by the value
        c = Counter(self.dic).most_common()
        # inital maximum
        res = [c[0][0]]
        for i in range(1,len(c)):
            # if next one is the same as 0 1
            if (c[i][1] == c[i-1][1]):
                res.append(c[i][0])
            else:
                # no more possible
                break
        return res
        