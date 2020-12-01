#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int> > resVec;
        sort(nums.begin(),nums.end());  
        vector<int> reala;
        int answer = target + 100000;
        for(int p1=0;p1<nums.size();p1++){
            if(p1>0 && nums[p1] == nums[p1-1])  
            continue;
            int p2 = p1+1;//begin
            int p3 = nums.size()-1;//end
            while(p2<p3){
                int a = nums[p1];
                int b = nums[p2];
                int c = nums[p3];
                if (abs(target-(a+b+c)) < abs(answer-target)){
                    answer = a+b+c;
                    reala.push_back(a);
                    reala.push_back(b);
                    reala.push_back(c);
                }
                if(b+c== -a + target){
                    vector<int> tempVec(3);
                    tempVec[0] = a;
                    tempVec[1] = b;
                    tempVec[2] = c;
                    resVec.push_back(tempVec);
                    while (p2 < p3 && nums[p2] == nums[p2 + 1])  
                        p2++;
                    while (p2 < p3 && nums[p3 - 1] == nums[p3])  
                        p3--;
                    p2++;
                    p3--;       
                }
                else if(b+c < -a + target){  
                    p2++;
                }
                else{  
                    p3--;
                }
            }       
        }
        return answer;
    }
};
int main(){	
}
