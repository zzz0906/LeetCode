class Solution {
public:
    int titleToNumber(string s) {
        int multi = 1;
        int res = 0;
        for (int i = s.size() - 1; i >= 1; i--){
            res += multi * ((s[i] - 'A') + 1);
            multi = multi * 26;
        } 
        res += multi * ((s[0] - 'A') + 1);
        return res;
    }
};