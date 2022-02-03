class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long long res = stoll(str);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};