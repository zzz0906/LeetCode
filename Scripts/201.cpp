class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long ans = m;
        // 15/2 = 7 .. 1 7/2 = 3 3/2 = 1 1/2 = 0  2/2 = 1 1/2 = 0  10

        int le = 0;
        int tmp = m;
        while (tmp != 0) {le++; tmp = tmp / 2;}
        int re = 0;
        tmp = n;
        while (tmp != 0) {re++; tmp = tmp / 2;}
        if (re-le >= 1) return 0;
        long long mtmp = m;
        for (long long i = mtmp+1; i <=n; i++)
            ans = ans & i;
        
        return ans;
    }
};