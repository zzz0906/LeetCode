class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> answer = nums;
        int i_place = 0; int j = 0;
        while (i_place < answer.size()){
            answer[i_place] = nums[j];
            j++;
            i_place += 2;
        }
        int rec = j - 1;
        i_place = 0;
        
        while (rec > -1){
            answer[i_place] = nums[rec];
            i_place += 2;
            rec--;
        }
        i_place = 1;
        j = nums.size() - 1;
        while (i_place < answer.size()){
            answer[i_place] = nums[j];
            j--;
            i_place += 2;
        }
        nums = answer;
    }
};