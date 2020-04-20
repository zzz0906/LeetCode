#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int left_wall = 0;
        int answer = 0;
        while (left_wall < height.size()-1) {
            int tmp_right_wall = left_wall + 1;
            int tmp_last = left_wall;
            while (tmp_right_wall < height.size() && height[tmp_right_wall] < height[tmp_last]){
                tmp_right_wall++;
                tmp_last++;
            }
            while (tmp_right_wall < height.size() && height[tmp_right_wall] > height[tmp_last]){
                tmp_right_wall++;
                tmp_last++;
            }
            if (tmp_right_wall != height.size()){
                int leorri = 0;
                leorri = max(height[tmp_right_wall],height[left_wall]);
                int last = left_wall;
                int right_wall = left_wall + 1;
                int tmp = 0;
                while (right_wall < height.size() && height[last] > height[right_wall]){
                    answer += height[last] - height[right_wall];
                    tmp = last;
                    last ++;
                    right_wall ++;
                }
                if (right_wall < height.size())
                    if (height[tmp] < height[right_wall] && height[right_wall] > leorri){
                        answer+=height[right_wall] -height[tmp];
                    }
                last ++;
                right_wall++;
                while (right_wall < height.size() && height[last] < height[right_wall]){
                    if (height[right_wall] <= leorri)
                        answer += height[right_wall] -height[last];
                    else
                        break;
                    last ++;
                    right_wall++;
                }
                if (right_wall == height.size())
                    break;
                left_wall = last;
            }
            else
                break;
        }
        return answer;
    }
};