class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<pair<int, int>> f(s.length(),make_pair(0,0));
        f[s.length() - 1] = s[s.length() - 1] == '0' ? make_pair(0,1) : make_pair(1,0);

        for (int i = s.length() - 2; i >= 0; i--){
            f[i].first =  min(f[i + 1].first, f[i + 1].second) + ((s[i] == '0') ? 0 : 1); // '0'
            f[i].second = f[i + 1].second + ((s[i] == '1') ? 0 : 1); //'1'
        }
        return min(f[0].first, f[0].second);
    }
};