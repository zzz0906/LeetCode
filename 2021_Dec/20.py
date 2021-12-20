import math
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # elements to store the answer
        res = []
        # sort the array
        arr.sort()
        # minimal diff answer; init as INT_MAX
        minimal_diff = 1 << 29
        # iterate to compute the diff for adjacent elements
        for i in range(1, len(arr)):
            # when it equal to the minimal diff
            if (abs(arr[i] - arr[i - 1]) == minimal_diff):
                res.append([arr[i-1], arr[i]])
            # when it's less than minimal diff
            elif (abs(arr[i] - arr[i - 1]) < minimal_diff):
                # update answer
                res = [[arr[i - 1], arr[i]]]
                # update minimal diff
                minimal_diff = abs(arr[i] - arr[i - 1])
        return res