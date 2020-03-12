#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > answer;
        int bucket[100000];
        int minbucket[100000];
        for (int i = 0; i < 100000;i++)
            bucket[i] = 0;
        for (int i = 0; i < nums.size();i++)
            if (nums[i] >= 0)
                bucket[nums[i]] =1;
            else
            {
                minbucket[-nums[i]] = 1;
            }
            
        for (int i = 0; i < nums.size();i++)
            for (int j = 0; j < nums.size();j++)
            if (j != i){
                if (-(nums[j] + nums[i]) < 0){
                    if (minbucket[(nums[j] + nums[i])] == 1){
                        vector<int> midv;
                        midv.push_back(nums[i]);
                        midv.push_back(nums[j]);
                        midv.push_back(-(nums[j] + nums[i]));
                        sort(midv.begin(), midv.end());
                        bool flag = true;
                        for (int k = 0; k < answer.size();k++)
                            if (midv == answer[k]){
                                flag = false;
                                break;
                            }
                        if (flag)
                            answer.push_back(midv);
                    }
                }
                else{
                  if (bucket[-(nums[j] + nums[i])] == 1){
                        vector<int> midv;
                        midv.push_back(nums[i]);
                        midv.push_back(nums[j]);
                        midv.push_back(-(nums[j] + nums[i]));
                        sort(midv.begin(), midv.end());
                        bool flag = true;
                        for (int k = 0; k < answer.size();k++)
                            if (midv == answer[k]){
                                flag = false;
                                break;
                            }
                        if (flag)
                            answer.push_back(midv);
                    }  
                }
            }
        return answer;
    }
};
int main(){	
}
