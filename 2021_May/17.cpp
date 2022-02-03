class Solution {
public:
    bool helper(string word1, string word2) {
        int m = word1.size(), n = word2.size(), i = 0;
        for (int j = 0; j < n; ++j) {
            if (word2[j] == word1[i]) ++i;
        }
        return i == m;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const std::string& first, const std::string& second){
                                            return first.size() < second.size();
                                            }
        );
        // vector<int> map_c(26,0);
        // vector<vector<int> > words_map(words.size(),map_c);
        // int index = 0;
        // for (auto word : words){
        //     for (auto c : word){
        //         words_map[index][c - 'a'] ++;
        //     }
        //     index += 1;
        // }
        vector<int> dp(words.size(),1);
        int res = 0;
        for (int i = 1; i < dp.size(); i++){
            for (int j = 0; j < i; j++){
                if (words[j].size() + 1 != words[i].size())
                    continue;
                if (helper(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            res = max(res,dp[i]);
        }
        if (words.size() == 1)
            return 1;
        else
            return res;
    }
};