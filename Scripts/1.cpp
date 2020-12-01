#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0;i<nums.size();i++)
        	for (int j =0;j<nums.size();j++)
        		if (nums[i]+nums[j] == target && i!=j){
        			int array[]={i,j};
        			return vector<int>(array,array+2);
				}
    }	
};
