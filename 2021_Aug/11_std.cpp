class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> m;
        for (int num : A) ++m[num];
        vector<int> keys;
        for (auto &a : m) keys.push_back(a.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int key : keys) {
            if (m[key] > m[2 * key]) return false;
            m[2 * key] -= m[key];
        }
        return true;
    }
};