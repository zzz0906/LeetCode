class Solution {
public:
    int concatenatedBinary(int n) {
        int power = 1;
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            //transfer to binary
            int tmp = i;
            while (tmp != 0){
                //long long tmp_v = ((tmp % 2) % 1000000007) * (power % 1000000007);
                ans = (ans + (((tmp % 2) % 1000000007) * (power % 1000000007)) % 1000000007) % 1000000007;
                tmp /= 2;
                power *= 2;
                power %= 1000000007;
            }
        }
        return ans;
    }
};