#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size();i++)
            while (nums[i] > 0 && nums[i]-1 < nums.size() && nums[nums[i]-1] != nums[i]){
                //cout<<nums[i]<<" "<<nums[nums[i]-1]<<endl;
                swap(nums[i], nums[nums[i]-1]);}
        //cout<<nums[0]<<endl;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
int main(){
    Solution s;
    int a[4] = {3,4,-1,1};
    vector<int> tmp(a,a+4);
    s.firstMissingPositive(tmp);
}