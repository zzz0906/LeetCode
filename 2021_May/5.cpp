#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int f[1000];
    int jump(vector<int>& nums) {
        for (int i = 0; i < nums.size();i++){
            f[i] = 100000;
        }
        f[0] = 0;
        for (int i = 0; i < nums.size();i++){
            for (int j = 1; j <nums[i];j++)
                f[i+j] = min(f[i+j],f[i]+1);
        }
        return f[nums.size()-1];
    }
};