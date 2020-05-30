class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int last = INT_MAX;
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != last){
                answer++;
                count = 1;
                last = nums[i];
            }else{
                if (count == 1){
                    count++;
                    answer++;
                }else{
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }
        }
        return answer;
    }
};