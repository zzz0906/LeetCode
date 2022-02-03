class NumArray {
public:
    NumArray(vector<int>& nums) {
        int tmp = 0;
        this->prefix_sum.push_back(0);
        for (int i = 0; i < nums.size(); i++){
            tmp += nums[i];
            this->prefix_sum.push_back(tmp);
        }
    }
    
    int sumRange(int i, int j) {
        return this->prefix_sum[j + 1] - this->prefix_sum[i]; 
    }
private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */