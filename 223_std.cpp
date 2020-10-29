class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum1 = (C - A) * (D - B), sum2 = (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) return sum1 + sum2;
        return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;
    }
};