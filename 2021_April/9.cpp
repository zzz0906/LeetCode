class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>> c_place;
        int pos = 0;
        for (auto c: order){
            c_place[c] = pos;
            pos++;
        }
        char last = words[0][0];
        for (int i = 1; i < words.size(); i++){
            if (c_place[words[i][0]] < c_place[last])
                return false;
            last = words[i][0];
        }
        return true;
    }
};