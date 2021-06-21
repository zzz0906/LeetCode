class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = n * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!helper(grid, mid)) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    bool helper(vector<vector<int>>& grid, int mid) {
        int n = grid.size();
        unordered_set<int> visited{0};
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        stack<int> st{{0}};
        while (!st.empty()) {
            int i = st.top() / n, j = st.top() % n; st.pop();
            if (i == n - 1 && j == n - 1) return true;
            for (auto dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || x >= n || y < 0 || y >= n || visited.count(x * n + y) || grid[x][y] > mid) continue;
                st.push(x * n + y);
                visited.insert(x * n + y);
            }
        }
        return false;
    }
};