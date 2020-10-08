class Solution {
public:
    vector<vector<char>> final_grid;
    void dfs(int i, int j, int current){
        if (i < 0 || j < 0 || i >= final_grid.size() || j >= final_grid[0].size()) return;
        if (final_grid[i][j] == '1'){
            final_grid[i][j] = '0';
            dfs(i+1,j,current);
            dfs(i-1,j,current);
            dfs(i,j+1,current);
            dfs(i,j-1,current);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int current = 0;
        final_grid = grid;
        for (int i = 0; i < final_grid.size(); i++)
            for (int j = 0; j < final_grid[i].size(); j++){
                if (final_grid[i][j] == '1'){
                    current++;
                    dfs(i,j,current);
                }
            }
        return current;     
    }
};