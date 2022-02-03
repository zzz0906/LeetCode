class Solution {
public:
    int removePalindromeSub(string s) {
        if (s == "") return 0;
        bool f = true;
        for (int i = 0; i < s.length()/2; i++)
            if (s[i] != s[s.length() - 1 - i]){
                f = false;
                break;
            }
        if (f == true) return 1;
        return 2;
    }
};