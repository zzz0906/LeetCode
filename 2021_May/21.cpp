class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //0 -> a
        //0 -> z
        vector<unordered_set<int>> same;
        for (int i = 0; i < pattern.length(); i++){
            unordered_set<int> tmp;
            for (int j = i + 1; j < pattern.length(); j++){
                if (pattern[i] == pattern[j])
                    tmp.insert(j);
            }
            same.push_back(tmp);
        }
        vector<string> res;
        for (auto word : words){
            if (word.length() != pattern.length())
                continue;
            int index = 0;
            bool det = true;
            //equal
            for (auto c : word){
                for (auto after_pos : same[index]){
                    if (c != word[after_pos]){
                        det = false;
                        break;
                    }
                }
                if (!det)
                    break;
                index ++;
            }
            //not eqaul
            index = 0;
            if (det){
                for (int i = 0; i < word.length(); i++){
                    for (int j = i + 1; j < word.length(); j++){
                        if (word[i] == word[j] && (!same[index].count(j)))
                            det = false;
                    }
                    index ++;
                }
            }
            if (det)
                res.push_back(word);
        }
        return res;
    }
};