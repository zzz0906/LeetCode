class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # monotonic stack
        # store the index!!
        mStack = []
        res = []
        # construct a circle by copy it the end
        circle = copy.deepcopy(nums)
        circle.extend(nums)
        for i in range(len(circle) - 1, -1, -1):
            # for the copy nums do not put them in the answer
            if (i >= len(nums)):
                while (len(mStack) > 0 and circle[i] >= circle[mStack[-1]]):
                    mStack.pop(-1)
            else:
                # see the answer of next greater I
                # pop out who have smaller elements and far away
                while (len(mStack) > 0 and circle[i] >= circle[mStack[-1]]):
                    mStack.pop(-1)
                # no element
                if (len(mStack) == 0):
                    res.append(-1)
                else:
                    if (circle[mStack[-1]] == circle[i] and mStack[-1] - len(nums) == i):
                        res.append(-1)
                    else:
                        # if its in the copy nums, cicrle one
                        if (mStack[-1] >= len(nums)):
                            res.append(nums[mStack[-1] - len(nums)])
                        # normal number
                        else:
                            res.append(nums[mStack[-1]])
            mStack.append(i)
        res.reverse()
        return res
            