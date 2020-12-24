class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        int index = -1;
        for (int i = 1; i < digits.length(); i++)
            if (digits[i] - '0' > digits[0] - '0'){
                index = i;
            }
        if (index == -1) return -1;
        char tmp = digits[index];
        digits[index] = digits[0];
        digits[0] = tmp;
        long long re = stoll(digits);
        if (re > INT_MAX) return -1;
        else return re;
    }
};