import heapq
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # sort by capital
        cp = [(-p, c) for p,c in zip(profits, capital)]
        cp.sort(key = lambda x:x[1])
        
        # reachable capital heap by priority
        i = 0
        reachable = []
        
        for i in range(len(cp)):
            if cp[i][1]<=w:
                reachable.append(cp[i])
                i+=1
            else: break
                
        #heapify this by min heap; 
        heapq.heapify(reachable)
        
        # we can still invest and we have k index rest
        while reachable and k > 0:
            p, _ = heapq.heappop(reachable)
            w += -p #pulls out max profit from the reachable capital
            k -= 1
            
            #now add more items
            while i < len(cp) and cp[i][1] <= w:
                heapq.heappush(reachable, cp[i])
                i += 1
                
        return w
        