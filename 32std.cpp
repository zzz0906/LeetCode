#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), maxLen = 0;
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++) {
            int j = i-2-dp[i-1];
            if(s[i-1]=='(' || j<0 || s[j]==')') 
                dp[i] = 0;
            else {
                dp[i] = dp[i-1]+2+dp[j];
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};