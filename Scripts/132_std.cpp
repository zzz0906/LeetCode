class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n));
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {// p[j+1][i-1] updated from before 
                    p[j][i] = true;
                    f[i] = (j == 0) ? 0 : min(f[i], f[j - 1] + 1);
                }
            }
        }
        return f[n - 1];
    }
};