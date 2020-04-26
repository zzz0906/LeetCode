#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            ++res;
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]); // only to find the max reach point in this time answer + 1.
            }
            if (pre == cur) return -1; // May not need this
        }
        return res;
    }
};