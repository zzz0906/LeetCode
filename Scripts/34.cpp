#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        if (nums.size() == 0){
            answer.push_back(-1);
            answer.push_back(-1);
            return answer;
        }
        vector<int>::iterator first = lower_bound(nums.begin(), nums.end(),target);
        vector<int>::iterator end = upper_bound(nums.begin(), nums.end(),target);
        //cout<<*first<<endl;
        int index1,index2;
        if (first == nums.end()) 
            index1 = -1;
        else{
            if (*first == target)
                index1 = first - nums.begin();
            else
                index1 = -1;
        }
        answer.push_back(index1);
        cout<<*end<<endl;
        if (end == nums.end()){
            index2 = -1;
            answer.push_back(-1);
        }
        else {
            if (*first == target){
                index2 = end - nums.begin();
                if (*end == target)
                    answer.push_back(index2);
                else
                    answer.push_back(index2-1);
            }
            else
            {
                index2 = -1;
                answer.push_back(index2);
            }
        }
        return answer;
    }
};
int main(){
    Solution s;
    vector<int> tmp;
    tmp.push_back(3);
    //tmp.push_back(2);
    /*tmp.push_back(3);
    tmp.push_back(3);
    tmp.push_back(4);
    tmp.push_back(6);*/
    cout<<s.searchRange(tmp,3)[0]<<" "<<s.searchRange(tmp,3)[1]<<endl;

}