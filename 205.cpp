class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,vector<int>> positions;
        unordered_map<char,vector<int>> positiont;
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++){
            if (positions.count(s[i]) == 0){
                if (positiont.count(t[i]) != 0) return false;
                else{
                    vector<int> tmp1; vector<int> tmp2;
                    tmp1.push_back(i); tmp2.push_back(i);
                    positions[s[i]] = tmp1; positiont[t[i]] = tmp2;
                }
            }else{
                if (positiont.count(t[i]) == 0) return false;
                vector<int> tmp1 = positions[s[i]]; vector<int> tmp2 = positiont[t[i]];
                if (tmp1.size() != tmp2.size()) return false;
                for (int j = 0; j < tmp1.size(); j++)
                    if (tmp1[j] != tmp2[j]) return false;
                tmp1.push_back(i);tmp2.push_back(i);
                positions[s[i]] = tmp1; positiont[t[i]] = tmp2;
            }
        }
        return true;
    }
};