class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<string>> dp(1 << n, vector<string>(n));
        vector<vector<int>> overlap(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (i == j) continue;
        		for (int k = min(A[i].size(), A[j].size()); k > 0; --k) {
        			if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
        				overlap[i][j] = k;
        				break;
        			}
        		}
        	}
        }
        for (int i = 0; i < n; ++i) dp[1 << i][i] += A[i];
        for (int mask = 1; mask < (1 << n); ++mask) {
        	for (int j = 0; j < n; ++j) {
        		if ((mask & (1 << j)) == 0) continue;
        		for (int i = 0; i < n; ++i) {
        			if (i == j || (mask & (1 << i)) == 0) continue;
                    //we only need to update the j position to zero and end with i. other position we do not care. Thus, we use a xor to modify the j's position's value.
        			string t = dp[mask ^ (1 << j)][i] + A[j].substr(overlap[i][j]); 
        			if (dp[mask][j].empty() || t.size() < dp[mask][j].size()) {
        				dp[mask][j] = t;
        			}
        		}
        	}
        }
        int last = (1 << n) - 1;
        string res = dp[last][0];
        for (int i = 1; i < n; ++i) {
        	if (dp[last][i].size() < res.size()) {
        		res = dp[last][i];
        	}
        }
        return res;
    }
};