class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count0[2][33];
        memset(count0, 0, 66*sizeof(int));
        long long res = 0;
        for (auto num: nums){
            for (int i = 0; i < 32; i++){
                count[(num >> i) & 1][i] += 1;
            }
        }
        for (int i = 0; i < 32; i++)
            res += count[0][i]*count[1][i];
        return int(res);
    }
};