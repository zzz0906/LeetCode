class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0; int right = nums.size() - 1;
        // 0 6
        while (left < right) {
            int mid = left + (right - left) / 2; // 0 3 6
            
            // 1 1 2 
            if (mid == left){
                if (left == 0) return nums[left];
                if (right == nums.size() - 1) return nums[right];
                if (nums[left] == nums[left - 1]) return nums[right];
                return nums[left];
            }
            int numberOfL = mid;
            if (numberOfL % 2 == 0){
            // 0 0 1
            // 5 5 6
                if (nums[mid] == nums[mid + 1]){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }else{
                // 11 2mid
                if (nums[mid] == nums[mid + 1]){
                    right = mid - 1;
                }else{
                    left = mid;
                }
                
            }
        }
        return nums[left];
    }
};