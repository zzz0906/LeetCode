class Solution {
public:
    int largestPalindrome(int n) {
        int upper = pow(10, n) - 1, lower = upper / 10;
        for (int i = upper; i > lower; --i) {
            string t = to_string(i);
            long p = stol(t + string(t.rbegin(), t.rend()));
            for (long j = upper; j * j > p; --j) {
                if (p % j == 0) return p % 1337;
            }
        }
        return 9;
    }
};