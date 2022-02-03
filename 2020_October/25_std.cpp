class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                  if (dp[i - k * k] == false) { //means loose
                      dp[i] = true;
                      break;
                  }
            }
        }
        return dp[n];
    }
};