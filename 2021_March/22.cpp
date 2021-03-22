class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        unordered_set<string> st;
        unordered_map<string, string> m1;
        unordered_map<string, string> m2;
        for (int i = 0; i < wordlist.size(); ++i) {
            string word = wordlist[i];
            st.insert(word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!m1.count(word)) m1[word] = wordlist[i];
            // add all lowercase words to hashset
            for (char &c : word) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '_';
            }
            if (!m2.count(word)) m2[word] = wordlist[i];
            // add all characters to the wordlist
        }
        for (string query : queries) {
            if (st.count(query)) {
                res.push_back(query);
                continue;
            }
            transform(query.begin(), query.end(), query.begin(), ::tolower);
            if (m1.count(query)) {
                res.push_back(m1[query]);
                continue;
            }
            for (char &c : query) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '_';
            }
            if (m2.count(query)) {
                res.push_back(m2[query]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
};