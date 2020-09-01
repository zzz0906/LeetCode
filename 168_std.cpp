class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            if (n % 26 == 0) {
                res += 'Z';
                n -= 26;
            } else {
                res += n % 26 - 1 + 'A';
                n -= n % 26;
            }
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};