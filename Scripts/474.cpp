class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector values<pair<int,int>>;
        for (auto str : strs) {
            int ones = 0, zeros = 0;
            for (auto c : str){
                if (c == '0')
                    zeros ++;
                else
                    ones ++;
            }
            values.push_back(make_pair(zeros, ones));
        }
        vector<vector<vector<int>>> DP(strs.size(), vector<vector<int>(m,vector<int>(n,0))>);
        int res = 0;
        for (int i = 0; i < strs.size(); i++)
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= n; k++){
                    if (i == 0){
                        if (i - values[i].first >= 0 && j - values[i].second >= 0){
                            dp[i][j - values[i].first][k - values[i].second] = 1;
                        }else{
                            dp[i][j][k] = 0;
                        }
                    }else{
                        if (i - values[i].first >= 0 && j - values[i].second >= 0){
                            dp[i][j - values[i].first][k - values[i].second] = max(dp[i-1][j][k] + 1, dp[i-1][j - values[i].first][k - values[i].second]);
                        }else{
                            dp[i][j][k] = dp[i-1][j][k];
                        }
                    }
                    if (i == strs.size() - 1){
                        res = max(res,dp[i][j][k]);
                    }
                }
        return res;
    }
};