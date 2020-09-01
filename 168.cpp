class Solution {
public:
    char flag[30];
    string convertToTitle(int n) {
        for (int i = 1; i <= 26; i++)
            flag[i] = 65+i-1;
        flag[0] = 'Z';
        int tmp = n/26;
        int remain = n%26;
        string s = flag[remain];
        while (tmp != 0){
            remain = tmp % 26;
            tmp = tmp / 26;
            s += flag[remain];
        }
        return s;
    }
};