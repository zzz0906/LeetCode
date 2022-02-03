// Author: Huahua
class DSU {
public:
  DSU(int n): p_(n, -1) {}
  int find(int x) {
    return p_[x] == -1 ? x : p_[x] = find(p_[x]);
  }  
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) p_[x] = y;    
  }
private:
  vector<int> p_;
};
 
class Solution {
public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    map<int, vector<pair<int, int>>> mp; // val -> {positions}
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        mp[matrix[y][x]].emplace_back(x, y);
    vector<int> rx(n), ry(m);
    for (const auto& [val, ps]: mp) {
      DSU dsu(n + m);
      vector<vector<pair<int, int>>> cc(n + m); // val -> {positions}
      for (const auto& [x, y]: ps)
        dsu.merge(x, y + n);
      for (const auto& [x, y]: ps)        
        cc[dsu.find(x)].emplace_back(x, y);      
      for (const auto& ps: cc) {
        int rank = 1;
        for (const auto& [x, y]: ps)
          rank = max(rank, max(rx[x], ry[y]) + 1);
        for (const auto& [x, y]: ps)
          rx[x] = ry[y] = ans[y][x] = rank;   
      }      
    }
    return ans;
  }
};