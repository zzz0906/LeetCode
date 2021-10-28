class Solution:
    res = 0
    gGrid = [[]]
    beenTo = [[]]
    # def dfs(self,x, y):
    #     global res, gGrid, beenTo
    #     dirs = [[0,1],[1,0],[-1,0],[0,-1]]
    #     for dir in dirs:
    #         if (x + dir[0] >= 0 and x + dir[0] < len(gGrid) and y + dir[1] >= 0 and y + dir[1] < len(gGrid[0]) and not beenTo[x + dir[0]][y + dir[1]]):
    #             res += 3

    #             self.dfs(x + dir[0], y + dir[1])
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        bfsQ = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j] == 1):
                    bfsQ.append([i,j])
                    break
        beenTo = [[False]*len(grid[0]) for i in range(len(grid))]
        beenTo[bfsQ[0][0]][bfsQ[0][1]] = True
        res = 4
        while (len(bfsQ) > 0):
            head = bfsQ[0]
            bfsQ = bfsQ[1:] # pop
            # beenTo[head[0]][head[1]] = True
            
            dirs = [[0,1],[1,0],[-1,0],[0,-1]]
            x = head[0]
            y = head[1]
            for dir in dirs:
                if (x + dir[0] >= 0 and x + dir[0] < len(grid) and y + dir[1] >= 0 and y + dir[1] < len(grid[0]) and (not beenTo[x + dir[0]][y + dir[1]]) and grid[x + dir[0]][y + dir[1]] == 1):
                    res += 2
                    bfsQ.append([x + dir[0], y + dir[1]])
                    beenTo[x + dir[0]][y + dir[1]] = True
        return res
        # 10 -= 1 += 3
        # global res, gGrid, beenTo

        # gGrid = grid
        # beenTo = [[False]*len(gGrid[0]) for i in range(len(gGrid))]
        # for i in range(len(grid)):
        #     for j in range(len(grid[0])):
        #         if (grid[i][j] == 1):
        #             res = 4
        #             self.dfs(i,j)
        #             break

