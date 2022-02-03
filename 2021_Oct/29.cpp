class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         vector<vector<int>> timestamp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
         queue<pair<int, int>> q;
         for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 2){
                    timestamp[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        while (q.size() > 0){
            pair<int, int> head = q.front();
            q.pop();
            vector<vector<int> > dirs {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
            int x = head.first;
            int y = head.second;
            for (auto dir : dirs){
                if (x + dir[0] >= 0 && x+ dir[0] < grid.size() && y + dir[1] >= 0 && y+ dir[1] < grid[0].size() && grid[x + dir[0]][y + dir[1]] != 0 && timestamp[x][y] < timestamp[x + dir[0]][y + dir[1]] - 1){
                    timestamp[x + dir[0]][y + dir[1]] = timestamp[x][y] + 1;
                    grid[x + dir[0]][y + dir[1]] = 2;
                    q.push(make_pair(x + dir[0], y + dir[1]));
                }
            }
        }
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    return -1;
                else if (grid[i][j] == 2)
                    res = max(res,timestamp[i][j]);
        
        return res;
    }
};