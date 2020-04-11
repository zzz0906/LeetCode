#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int position;
    bool flag;
    void search(int st, int ed, vector<int>& array,int target){
        if (st == ed-1){
            if (array[st] == target){
                position = st;
                flag = true;
                return;
            }
            if (array[ed] == target){
                position = ed;
                flag = true;
                return;
            }
        }
        if (st == ed){
            if (array[ed] == target){
                position = ed;
                flag = true;
                return;
            }
        }
        if (st > ed) return;
        int mid = (st + ed) /2;
        if (array[mid] < target)
            search(mid+1,ed,array,target);
        else {
            if (array[mid] > target)
                search(st,mid-1,array,target);
            else if (array[mid] == target){
                position = mid;
                flag = true;
                return;
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        flag = false;
        int start = 0;
        int end = nums.size();
        vector<int> answer;
        search(start, end, nums,target);
        if (nums[position] != target) {
            answer.push_back(-1);
            answer.push_back(-1);
        }else{
            int tmp1 = position;
            int tmp2 = position;
            while (nums[tmp1] == target){
                tmp1--;
            }
            while (nums[tmp2] == target){
                tmp2++;
            }
            tmp1 ++;
            tmp2 --;
            answer.push_back(tmp1);
            answer.push_back(tmp2);
            return answer;
        }
    }
}