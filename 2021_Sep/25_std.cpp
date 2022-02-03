struct triple {
    int x, y;
    int rest;
    triple(int _x, int _y, int _r): x(_x), y(_y), rest(_r) {}
};


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        if(m==1 && n==1)return 0;
        k = min(m + n - 3, k);
        bool visited[m][n][k+1];
        memset(visited, false, sizeof(visited));
        queue<triple> q;
        q.emplace(0, 0, k);
        visited[0][0][k] = true;

        for(int step = 1; q.size() > 0; ++step){
            int cnt = q.size();
            for(int _ = 0; _ < cnt; ++_){
                triple cur = q.front();
                q.pop();
                for(int d = 0; d < 4; ++d){
                    int x = cur.x + dirs[d][0], y = cur.y + dirs[d][1];
                    if(x >=0 && x < m && y >= 0 && y < n){
                        if(grid[x][y] == 0 && !visited[x][y][cur.rest]){
                            if(x == m - 1 && y == n - 1)return step;
                            q.emplace(x, y, cur.rest);
                            visited[x][y][cur.rest] = true;
                        }else if(grid[x][y] == 1 && cur.rest > 0 && !visited[x][y][cur.rest - 1] ){
                            q.emplace(x, y, cur.rest - 1);
                            visited[x][y][cur.rest - 1] = true;
                        }
                    }

                }
            }
        }
        return -1;
        
    }
};
