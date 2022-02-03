class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty() || envelopes[0].size() == 0) return 0;
        int res = 1, n = envelopes.size();
        vector<int> dp(n,1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; ++j)
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            res = max(res,dp[i]);
        }
        return res;
            // if (envelopes[i][0] > envelopes[i-1][0] && envelopes[i][1] > envelopes[i-1][1])
            //     dp[i] = dp[i-1] + 1;
            // else
            //     dp[i] = dp[i-1];
    }
};