class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int mx = 0, n = wall.size();
        unordered_map<int, int> m;
        for (auto &row : wall) {
            int sum = 0, cnt = row.size();
            for (int i = 0; i < cnt - 1; ++i) {
                sum += row[i];
                ++m[sum];
                mx = max(mx, m[sum]);
            }
        }
        return n - mx;
    }
};