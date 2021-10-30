class Solution {
public:
    string longestDupSubstring(string s) {
        string res = "";
        int n = s.size(), left = 0, right = n, M = 1e7 + 7;
        vector<int> power(n);
        for (int i = 0; i < n; ++i) {
            power[i] = (i == 0) ? 1 : (power[i - 1] * 26) % M;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            string dup = rabinKarp(s, mid, power);
            if (dup.size() > res.size()) {
                res = dup;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return res;
    }
    string rabinKarp(string s, int len, vector<int>& power) {
        if (len == 0) return "";
        int n = s.size(), cur = 0, M = 1e7 + 7;
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < len; ++i) {
            cur = (cur * 26 + (s[i] - 'a')) % M;
        }
        hash[cur] = {0};
        for (int i = len; i < n; ++i) {
            cur = ((cur - power[len - 1] * (s[i - len] - 'a')) % M + M) % M;
            cur = (cur * 26 + (s[i] - 'a')) % M;
            if (!hash.count(cur)) {
                hash[cur] = {i - len + 1};
            } else {
                for (int idx : hash[cur]) {
                    if (s.substr(idx, len) == s.substr(i - len + 1, len)) return s.substr(idx, len);
                }
                hash[cur].push_back(i - len + 1);
            }
        }
        return "";
    }
};