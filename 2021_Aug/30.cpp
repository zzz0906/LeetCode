class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty() || ops[0].empty()) return m * n;
        priority_queue<int> r, c;
        for (auto op : ops) {
            r.push(-op[0]);
            c.push(-op[1]);
        }
        return r.top() * c.top();
    }
};