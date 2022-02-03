class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() <= 2) return {};
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            dict.erase(word);
            int len = word.size();
            if (len == 0) continue;
            vector<bool> v(len + 1, false);
            v[0] = true;
            for (int i = 0; i < len + 1; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (v[j] && dict.count(word.substr(j, i - j))) {
                        v[i] = true;
                        break;
                    }
                }
            }
            if (v.back()) res.push_back(word);
            dict.insert(word);
        }
        return res;
    }
};