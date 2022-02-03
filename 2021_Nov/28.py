class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        # dfs
        def dfs(cur, graph):
            # if we reach the target return a two dimension array
            if (cur == len(graph) - 1):
                return [[cur]]
            paths = []
            for target in graph[cur]:
                # for each vertex we can reach, if we reach n - 1, there will be a list in next Paths
                nextPaths = dfs(target, graph)
                # if nextPath exist, it means we reach n - 1 and we need to append current node to get a path
                for nextPath in nextPaths:
                    paths.append([cur] + nextPath)
            return paths
        return dfs(0, graph)
            