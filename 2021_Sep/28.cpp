class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int numOfEven = 0, pos = 0;
        while (nums[numOfEven] % 2 != 0){
            numOfEven ++;
        }
        
        while (pos < nums.size()){
            swap(nums[pos], nums[numOfEven]);
            pos += 2;
            if (nums[numOfEven] % 2 != 0 || (nums[numOfEven] % 2 == 0 && numOfEven % 2 == 0 && numOfEven < pos)){
                numOfEven ++;
                while (numOfEven < nums.size() && (nums[numOfEven] % 2 != 0 || (nums[numOfEven] % 2 == 0 && numOfEven % 2 == 0 && numOfEven < pos)))
                    numOfEven ++;
            }else{
                
            }
        }
        
        return nums;
    }
};