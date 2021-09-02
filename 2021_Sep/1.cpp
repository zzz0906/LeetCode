class Solution {
public:
    vector<int> orig;
    int res;
    void dfs(int curIndex, int length,vector<bool>& visited){
        if (visited[curIndex]){
            res = max(res, length);
            return;
        }
        visited[curIndex] = true;
        dfs(orig[curIndex], length + 1, visited);
    }
    int arrayNesting(vector<int>& nums) {
        orig = nums;
        vector<bool> visited(nums.size(), false);
        res = 0;
        for (int i = 0; i < nums.size(); i++) {
            dfs(i,0,visited);
        }
        return res;
    }
};  