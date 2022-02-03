class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
    }
    int pow(int x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x % 1337;
        if (n % 2 == 0){
            long long res = pow(x % 1337, n / 2) % 1337;
            return res * res % 1337;
        }
        else{
            long long res = pow(x % 1337, n / 2) % 1337;
            return res * res % 1337 * x % 1337;
        }
    }
};