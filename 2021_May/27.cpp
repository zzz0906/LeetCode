class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int> > char_words;
        for (int i = 0; i < words.size(); i++){
            vector<int> tmp;
            for (int j = 0; j < 26; j++){
                tmp.push_back(0);
            }
            for (int j = 0; j < words[i].size(); j++){
                tmp[words[i][j] - 'a'] ++;
            }
            char_words.push_back(tmp);
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++){
                int sum = 0;
                for (int k = 0; k < 26; k++){
                    sum += char_words[i][k] * char_words[j][k];
                    if (sum > 0) break;
                }
                if (sum == 0){
                    int cur = words[i].length()*words[j].length();
                    ans = (cur > ans) ? cur:ans;
                }
            }
        return ans;
    }
};