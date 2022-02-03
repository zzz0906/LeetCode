class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int index = 0;
        while (index < nums.size()){
            if (index != nums[index] - 1 && nums[nums[index] - 1] == nums[index]){
                //res.push_back(nums[index]);
                // cout << 1 << endl;
            }else if (index != nums[index] - 1){
                int tmp = nums[nums[index] - 1];
                nums[nums[index] - 1] = nums[index];
                nums[index] = tmp;
                index --;
            }
            index ++;
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] - 1 != i){
                res.push_back(i+1);
            }
        return res;
    }
};