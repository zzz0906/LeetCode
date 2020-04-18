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
            int tmp_right_wall = left_wall + 1;
            while (tmp_right_wall < height.size() && height[tmp_right_wall] < height[left_wall])
                tmp_right_wall++;
            if (tmp_right_wall != height.size()){
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
                    if (height[tmp] < height[right_wall]){
                        answer+=height[right_wall] -height[tmp];
                    }
                last ++;
                right_wall++;
                while (right_wall < height.size() && height[last] < height[right_wall]){
                    answer += height[right_wall] -height[last];
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