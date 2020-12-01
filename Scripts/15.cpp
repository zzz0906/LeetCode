#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > resVec;
        sort(nums.begin(),nums.end());  

        for(int p1=0;p1<nums.size();p1++){
            if(nums[p1] >0)  // if > 0 that means no answer
            return resVec;
            if(p1>0 && nums[p1] == nums[p1-1])  
            continue;
            int p2 = p1+1;//begin
            int p3 = nums.size()-1;//end
            while(p2<p3){
                int a = nums[p1];
                int b = nums[p2];
                int c = nums[p3];
                if(b+c== -a){
                    vector<int> tempVec(3);
                    tempVec[0] = a;
                    tempVec[1] = b;
                    tempVec[2] = c;
                    resVec.push_back(tempVec);
                    while (p2 < p3 && nums[p2] == nums[p2 + 1])  //去除重复元素
                        p2++;
                    while (p2 < p3 && nums[p3 - 1] == nums[p3])  //去除重复元素
                        p3--;
                    p2++;
                    p3--;       
                }
                else if(b+c < -a){  
                    p2++;
                }
                else{  
                    p3--;
                }
            }       
        }
        return resVec;
    }
};
int main(){	
}
