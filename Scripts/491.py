class Solution:
    def dfs(self, pos, tmp):
        # only add to answer when size >= 2
        if (len(tmp) >= 2):
            # use a set to delete duplicates
            self.res.add(tuple(copy.deepcopy(tmp)))
        
        # when we reach the last element return
        if (pos == len(self.nums) - 1):
            return
        # enumerate next elements
        for i in range(pos + 1, len(self.nums)):
            # when next > current
            if (self.nums[i] >= self.nums[pos]):
                # add it
                tmp.append(self.nums[i])
                # dfs to next one
                self.dfs(i, tmp)
                # pop out it
                tmp.pop()
        return
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self.nums = nums
        self.res = set()
        
        for i in range(len(nums)):
            self.dfs(i, [nums[i]])
        
        return self.res
                    
            