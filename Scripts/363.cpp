class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            vector<int> sum(m);
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    sum[k] += matrix[k][j];
                }// sum[k] = row[k]'s sum
                // At first we only have the first number of row. -> 
                int curSum = 0;
                set<int> st{{0}};
                for (auto a : sum) {
                    curSum += a;
                    auto it = st.lower_bound(curSum - k);
                    if (it != st.end()) res = max(res, curSum - *it);
                    st.insert(curSum);
                }
            }
        }
        return res;
    }
};