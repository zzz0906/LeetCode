class Solution {
public:
    int integerBreak(int n) {
        //p1 + p2 + p3 = n
        //p1*p2...pn
        //3 2 1; 4 2 2; 5 2 3; 6 3 3; 7 3 4; 8 4 4; 9 3^3 = 27; 10  3 3 4; 11 3 3 5 = 45; 3 3 3 2 = 54;
        // DP?
        vector<int> dp(n + 1,0);
        dp[1] = 1;
        dp[2] = 1;
        if (n == 2) return 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++)
            for (int j = 1; j < i; j++){
                dp[i] = max(dp[i],dp[i-j]*dp[j]);
                dp[i] = max(dp[i],dp[i-j]*j);
                dp[i] = max(dp[i],(i-j)*dp[j]);
                dp[i] = max(dp[i],(i-j)*j);
            }
        return dp[n];
    }
};