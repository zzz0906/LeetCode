#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int po;
    bool flag;
    void find(int start,int end,vector<int>& nums){
        if (end < start)
            return;
        if ((end-1 > 0) && nums[end] > nums[end-1]){
            this->po = end;
            this->flag = true;
            return;
        }
        if (nums[(start+end)/2] > nums[start]){
            find((start+end)/2,end,nums);
            if (this->flag) return;
        }
        else{
            find(start,(start+end)/2,nums);
            if (this->flag) return;
        }
    }
    int search(vector<int>& nums, int target) {
        this->po = 0;
        this->flag = false;
        int start = 0;
        int end = nums.size();
        vector<int>::const_iterator first1 = nums.begin();
        vector<int>::const_iterator last1 = nums.begin() + this->po-1;

        vector<int>::const_iterator first2 = nums.begin() + this->po;
        vector<int>::const_iterator last2 = nums.end();
        vector<int> new1 = vector<int>(first1, last1);
        vector<int> new2 = vector<int>(first2, last2);
        vector<int>::const_iterator index = lower_bound(new1.begin(), new1.end(),target);
        
        
    }
};