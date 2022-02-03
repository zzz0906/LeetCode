class Solution {
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    const int r = heights.size();
    const int c = heights[0].size();
    int dp[100][100];
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;
    vector<int> dirs{0, -1, 0, 1, 0};
    for (int k = 0; k < r * c; ++k) {
      bool stable = true;
      for (int y = 0; y < r; ++y)
        for (int x = 0; x < c; ++x)
          for (int d = 0; d < 4; ++d) {
            int tx = x + dirs[d];
            int ty = y + dirs[d + 1];
            if (tx < 0 || tx == c || ty < 0 || ty == r) continue;
            int t = max(dp[ty][tx], abs(heights[ty][tx] - heights[y][x]));
            if (t < dp[y][x]) {
              stable = false;
              dp[y][x] = t;
            }
          }    
      if (stable) break;
    }
    return dp[r - 1][c - 1];
  }
};