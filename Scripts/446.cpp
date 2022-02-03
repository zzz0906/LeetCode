#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_set<pair<int,int>, pair_hash> records;
        long long res = 0;
        for (int i  = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int diff = nums[j] - nums[i];
                if (!records.count(make_pair(i,j))){
                    long curLen = 2;
                    int last = nums[j];
                    int lastIndex = j;
                    //cout << i << j;
                    for (int k = j + 1; k < nums.size(); k++){
                        if (nums[k] - last == diff){
                            records.insert(make_pair(lastIndex,k));

                            last = nums[k];
                            lastIndex = k;
                            curLen++;
                        }
                    }
                    // 32 - 10 - 5 - 1 = 
                    //cout << curLen << endl;
                    if (curLen >= 3){
                        res += (curLen - 1) * (curLen - 2) / 2;
                    }
                }
            }
        }

        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums{2,4,6,8,10};
    cout << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}