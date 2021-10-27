class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x != 0 || y != 0){
            int res1 = x & 1;
            int res2 = y & 1;
            if (res1 != res2){
                res ++;
            }
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};