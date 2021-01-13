class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;
        vector<char> inord;
        for (int i = 0; i < s.length(); i++){
            if ('0' <= s[i] && s[i] <= '9' || 'a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z')
            inord.push_back(s[i]);
        }
        for (int i = 0; i < inord.size(); i++){
            if (i >= inord.size()- 1 - i) break;
            if ('A' <= inord[i] && inord[i] <= 'Z') inord[i] = inord[i] - 'A' + 'a';
            if ('A' <= inord[inord.size()-1-i] && inord[inord.size()-1-i] <= 'Z') inord[inord.size()-1-i] = inord[inord.size()-1-i] - 'A' + 'a';
            if (inord[i] != inord[inord.size()-1-i])
                return false;
        }
        return true;
    }
};