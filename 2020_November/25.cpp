class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int g = 0;
        for (int i = 0; i < K; i++){
            g = (g*10+1) % K;
            if (g == 0) return i+1;
        }
        return -1;
    }
};