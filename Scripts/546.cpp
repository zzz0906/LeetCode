class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {{{0}}};
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= i; ++k) {
                dp[i][i][k] = (1 + k) * (1 + k);
            }   
        }
        for (int t = 1; t < n; ++t) {
            for (int j = t; j < n; ++j) {
                int i = j - t;
                for (int k = 0; k <= i; ++k) {
                    int res = (1 + k) * (1 + k) + dp[i + 1][j][0];
                    for (int m = i + 1; m <= j; ++m) {
                        if (boxes[m] == boxes[i]) {
                            res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                        }
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        return n == 0 ? 0 : dp[0][n - 1][0];
    }
};