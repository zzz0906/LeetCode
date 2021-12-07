import copy
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        # size == 1
        if (len(score) == 1):
            return ['Gold Medal']
        
        # size == 2
        if (len(score) == 2):
            if (score[0] > score[1]):
                return ['Gold Medal', 'Silver Medal']
            return ['Silver Medal', 'Gold Medal']
        
        # generate a sorted
        val = copy.deepcopy(score)
        val.sort()
        val.reverse()
        # print(val)
        
        # map score to its sorted value index
        v2i = {}
        index = 0
        for v in val:
            if (index == 0):
                v2i[v] = 'Gold Medal'
            elif (index == 1):
                v2i[v] = 'Silver Medal'
            elif (index == 2):
                v2i[v] = 'Bronze Medal'
            else:
                v2i[v] = str(index + 1)
            index += 1
        
        res = []
        for sc in score:
            res.append(v2i[sc])
        
        return res

        