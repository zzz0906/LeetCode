#include <vector>
#include <string>
#include <map>  
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > answer; 
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++){
            string cur = strs[i];
            vector<int> cnt(26);
            for (int j = 0; j < cur.size(); j++)
                cnt[int(cur[j]-'a')]++;
            string t = "";
            for (int j = 0; j < 26; j++)
                if (cnt[j] == 0) continue;
                else t += string(1, j + 'a') + to_string(cnt[j]);
            m[t].push_back(cur);
        }
        for (auto a : m)
            answer.push_back(a.second);   
        return answer;
    }
};