class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        int zerocount = 0;
        int res = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    ++zerocount;
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, 0, zerocount, res);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, int pathcount, int zerocount, int& res) {
        if (grid[x][y] == 2 && pathcount == zerocount) 
            ++res;
        const int M = grid.size();
        const int N = grid[0].size();
        int pre = grid[x][y];
        if (pre == 0)
            ++pathcount;
        grid[x][y] = -1;
        for (auto d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || grid[nx][ny] == -1)
                continue;
            dfs(grid, nx, ny, pathcount, zerocount, res);
        }
        grid[x][y] = pre;
    }
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};