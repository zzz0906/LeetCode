class Solution {
public:
    char flag[30];
    char flag2[30];
    string convertToTitle(int n) {
        for (int i = 0; i < 26; i++)
            flag[i] = 65+i;

        int tmp = n;
        int remain = 0;

        string s = "";

        while (tmp != 0){
            tmp = tmp - 1;
            remain = tmp % 26;
            tmp = tmp / 26;
            s += flag[remain];
        }
        reverse(s.begin(), s.end());
        return s;
    }
};