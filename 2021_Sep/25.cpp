class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int> > > dp(grid.size(), vector<vector<int> >> (grid[0].size, vector<int>(k,0)));
        if (gird[0][0] == 1){
            if (k - 1 > -1){
                dp[0][0][k - 1] = 1;
            }else{
                return 0;
            } 
        }else{
            dp[0][0][k] = 1;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++){
                for (int tmpk = 0; tmpk < k)
                if (i != 0 || j != 0){
                    if (i - 1 >= 0){
                        if (gird[i][j] == 1){

                        }else{
                            dp[i][j] =
                        }
                    }
                    if (j - 1 >= 0){

                    }
                    if (i - 1 >= 0 && j - 1 >= 0){

                    }
                }
                
            }
        }
    }
};