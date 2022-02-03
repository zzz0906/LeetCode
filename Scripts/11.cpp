#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int answer = min(height[left], height[right])*(right-left);
        cout<<answer;
        while (left < right){
            if (height[left] > height[right]){
                right--;
                answer = max(answer, min(height[left], height[right])*(right-left));        
            }else{
                left++;
                answer = max(answer, min(height[left], height[right])*(right-left));
            }
        }
        return answer;
    }
};
int main(){
    Solution solution;
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    cout<<solution.maxArea(a);
}