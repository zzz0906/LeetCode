class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            for (int j = 0; j < min((int)nums2.size(), k); ++j) {
                vector<int> tmp; tmp.push_back((nums1[i])); tmp.push_back((nums2[j]));
                res.push_back(tmp);
            }
        }
        sort(res.begin(), res.end(), [](vector<int> &a, vector<int> &b){return a[0] + a[1] < b[0] + b[1];});
        if (res.size() > k) res.erase(res.begin() + k, res.end());
        return res;
    }
};