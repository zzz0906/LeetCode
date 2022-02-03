class Solution(object):
    def criticalConnections(self, n, cons):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: List[List[int]]
        """
        g = collections.defaultdict(list)
        parent = [-1] * (1 + n)
        low = [float('inf')] * (1 + n)
        dfn = [0] * (1 + n)        
        self.time = 1
        res = []
        
        def tarjan(u):
            low[u] = self.time
            dfn[u] = self.time
            self.time += 1
            for v in g[u]:
                if not dfn[v]:
                    parent[v] = u
                    tarjan(v)
                    low[u] = min(low[u], low[v])  # 没访问过的肯定不是父节点, 不需要check
                    if low[v] > dfn[u]:
                        res.append([u, v]) # low[v] > dnf[u] 时, 说明v-u是桥/割边
                elif v != parent[u]: # 需要check
                    low[u] = min(low[u], dfn[v])

        for x, y in cons:
            g[x].append(y)
            g[y].append(x)
        
        for i in range(1, n + 1):
            if not dfn[i]:
                tarjan(i)
        return res