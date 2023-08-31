class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        d = {}
        def dfs(price, special, needs):
            if not needs:
                return 0
            # calculate the price without special offer
            res = sum([price[i] * needs[i] for i in range(len(needs))])
            # try to use each special offer
            for offer in special:
                # check if we can use this offer
                for i in range(len(needs)):
                    if needs[i] < offer[i]:
                        break
                else:
                    # use this offer
                    tmp = [needs[j] - offer[j] for j in range(len(needs))]
                    if tuple(tmp) not in d:
                        d[tuple(tmp)] = dfs(price, special, tmp)
                    res = min(res, offer[-1] + d[tuple(tmp)])
            return res
        return dfs(price, special, needs)