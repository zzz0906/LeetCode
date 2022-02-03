class Solution {
public:
    int kthFactor(int n, int k) {
        int cur = 0;
        for (int i = 1; i <= n; i++){
            if (n % i == 0) cur++;
            if (cur == k) return i;
        }
        return -1;
    }
};