class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        int length = max(num1.length(), num2.length());
        int cur = 0;
        int carry = 0;
        while (cur < length) {
            int sum = carry;
            sum += cur < num1.length() ? num1[cur] - '0' : 0;
            sum += cur < num2.length() ? num2[cur] - '0' : 0;
            if (sum < 10){
                carry = 0;
                res += ('0' + sum)
            } else{
                carry = 1;
                res += ('0' + sum - 10);
            }
            cur += 1;
        }
        res += carry > 0 ? "1" : "";
        reverse(res.begin(), res.end());
        return res;
    }
};