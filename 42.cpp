#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int left_wall = 0;
        int answer = 0;
        while (left_wall < height.size()-1) {
            int right_wall = left_wall + 1;
            int baseline = 100000;
            while (right_wall < height.size() && height[right_wall] < height[left_wall]){
                if (height[right_wall] < baseline) baseline = height[right_wall];
                right_wall++;
            }
            if (right_wall != height.size() && height[right_wall] >= height[left_wall]){
                answer += (1) * (right_wall - left_wall-1);
                //cout<<left_wall<<" "<<right_wall<<" "<<1 * (right_wall - left_wall-1)<<endl;
                left_wall++;
            }else
            {
                left_wall++;
            }
        }
        return answer;
    }
};