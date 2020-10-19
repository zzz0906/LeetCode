class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 10) return res;
        unordered_map<string,int> stat;
        for (int i = 0; i < s.length()-9;i++){
            string cur = s.substr(i,10);
            if (stat.count(cur) == 0) stat[cur] = 1;
            else stat[cur] += 1;
        }
        for (auto i:stat)
            if (i.second >= 2) res.push_back(i.first);
        return res;
    }
};