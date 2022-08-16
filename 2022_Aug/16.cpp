class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set<char> have;
        for (int i = 0; i < s.length(); i++){
            if (have.count(s[i]))
                continue;
            bool dup = true;
            for (int j = i + 1; j < s.length(); j++){
                if (s[i] == s[j]){
                    dup = false;
                    break;
                }
            }
            if (dup)
                return i;
            have.insert(s[i]);
        }
        return -1;
    }
};