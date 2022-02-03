class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pastMin = INT_MAX;
        int res = INT_MIN;
        for (auto p : prices){
            res = max(p - pastMin, res);
            pastMin = min(p, pastMin);
        }
        return res > 0 ? res : 0;
    }
};