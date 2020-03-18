#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.empty())
            return res;
        
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 3; ++i) {
            for(int j = i + 1; j < num.size() - 2; ++j) {
                int left = j + 1, right = num.size() - 1;
                while(left < right) {
                    int curSum = num[i] + num[j] + num[left] + num[right];
                    if(curSum == target) {
                        int tmpa [4] = {num[i], num[j], num[left], num[right]};
                        vector<int> tmp(tmpa,tmpa+4);
                        res.push_back(tmp);
                        
                        while(left < right && num[left] == num[left + 1])
                            ++left;
                        while(left < right && num[right - 1] == num[right])
                            --right;
                        ++left;
                        --right;
                    } else if(curSum < target)
                        ++left;
                    else
                        --right;
                }
                while(j < num.size() && num[j] == num[j + 1])
                    ++j;
            }
            while(i < num.size() && num[i] == num[i + 1])
                ++i;
        }
        return res;
    }
};

int main(){
    int al[6] = {1,0,-1,0,-2,2};
    vector<int> alv(al,al+5);
    Solution s;
    s.fourSum(alv,0);
}