class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<vector<int>> prefix;
        if (s == "") return 0;
        int res = 0;
        vector<int> first;
        for (int i = 0; i < 26; i++)
            first.push_back(0);
        prefix.push_back(first);
        int index = 1;
        for (char c : s){
            vector<int> last = prefix[index-1];
            last[c-'a'] ++;
            prefix.push_back(last);
            index ++;
        }
        for (int i = 0; i <= s.size(); i++)
            for (int j = i+1; j <= s.size(); j++){
                vector<int> ed = prefix[j];
                vector<int> st = prefix[i];
                bool flag = true;
                for (int i = 0; i < 26; i++){
                    if (((ed[i] - st[i]) > 0) && ((ed[i] - st[i]) < k)){
                        flag = false;
                        break;
                    }
                }
                if (flag && (j-i) > res){
                    res = j-i;
                }
            }
        return res;
    }
};