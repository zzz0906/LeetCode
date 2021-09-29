class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((sqrt(8*(double)n + 1) - 1) / 2);
    }
};