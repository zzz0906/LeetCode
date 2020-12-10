#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<int> comb;
        vector<int> et1;
        vector<int> et2;
        vector<vector<int> > answer;
        for (int i = 0; i < nums.size();i++) 
            for (int j = i+1;  j < nums.size();j++) 
                if (i != j ) {
                    comb.push_back(nums[i] + nums[j]);
                    et1.push_back(i);
                    et2.push_back(j);
                }
        int left = 0; int right = comb.size()-1;
        sort(comb.begin(),comb.end());
        while (left < right){
            while (comb[left] + comb[right] == target){
                int end = left;
                while (comb[left] == comb[end])
                    end++;
                int st = right;
                while (comb[right] == comb[st])
                    st--;
                for (int k = left; k<=end;k++)
                    for (int l = st; l<=right;l++){
                        if (et1[k] != et2[l] && et1[k] != et1[l] && et2[k] != et2[l] && et2[k] != et1[l]){
                            vector<int> mid;
                            mid.push_back(nums[et1[k]]);
                            mid.push_back(nums[et2[k]]);
                            mid.push_back(nums[et1[l]]);
                            mid.push_back(nums[et2[l]]);
                            answer.push_back(mid);
                        }
                    }
                left = end + 1;
                right = st - 1;
            }
            if (comb[left] < target - comb[right])
                left ++;
            else right--;
        }
        for (int i = 0; i < answer.size();i++)
            for (int j = 0; j < answer[i].size();j++)
                cout<<answer[i][j]<<endl;
        return answer;
    }
};
int main(){
    int al[6] = {1,0,-1,0,-2,2};
    vector<int> alv(al,al+5);
    Solution s;
    s.fourSum(alv,0);
}