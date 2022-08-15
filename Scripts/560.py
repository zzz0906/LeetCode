import collections
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        prefix_sum = 0
        past = collections.defaultdict(int)
        past[0] = 1
        for num in nums:
            prefix_sum += num
            if prefix_sum - k in past:
                res += past[prefix_sum - k]
            past[prefix_sum] += 1
        return res