class Solution {
public:
    bool ans;
    bool dfs(int current, bool turn) {
        return dfs(current - 1, !turn) || dfs(current - 2, !turn) || dfs(current - 3, !turn);
    }
    bool canWinNim(int n) {
        ans = false;
        dfs(n,true);
        return ans;
    }
};