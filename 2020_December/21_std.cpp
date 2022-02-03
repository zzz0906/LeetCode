class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size(), res = A[n - 1] - A[0];
        int left = A[0] + K, right =  A[n - 1] - K;
        for (int i = 0; i < n - 1; ++i) {
            int high = max(right, A[i] + K);
            int low = min(left, A[i + 1] - K);
            res = min(res, high - low);
        }
        return res;
    }
};