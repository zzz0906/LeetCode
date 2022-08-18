
class Solution:
    def minSetSize(self, arr: list[int]) -> int:
        count = {}
        for value in arr:
            if value in count:
                count[value] += 1
            else:
                count[value] = 1
        count = sorted(count.items(), key=lambda x: x[1], reverse=True)
        # print(count)
        res = 0
        remove = 0
        for key, value in count:
            res += 1
            remove += value
            if remove >= len(arr) / 2:
                return res
s = Solution()
print(s.minSetSize([1,2,2,3,3,3,4,4,4]))