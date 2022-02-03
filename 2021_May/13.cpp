class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        int n = S.size();
        for (int i = 1; i < n - 2; ++i) {
            vector<string> A = findAll(S.substr(1, i)), B = findAll(S.substr(i + 1, n - 2 - i));
            for (auto &a : A) {
                for (auto &b : B) {
                    res.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return res;
    }
    vector<string> findAll(string S) {
        int n = S.size();
        if (n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0')) return {};
        if (n > 1 && S[0] == '0') return {"0." + S.substr(1)};
        if (S[n - 1] == '0') return {S};
        vector<string> res{S};
        for (int i = 1; i < n; ++i) res.push_back(S.substr(0, i) + "." + S.substr(i));
        return res;
    }
};