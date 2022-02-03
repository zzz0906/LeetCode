class NumArray {
public:
    int lowbit(int x){
        return x & (-x);
    }
    NumArray(vector<int>& nums) {
        this->length = nums.size() + 1;
        this->fewick_tree = new int[this->length];
        memset(this->fewick_tree,0,sizeof(int)*(length));
        for (int i = 0; i < nums.size(); i++){
            this->fewick_tree[i + 1] += nums[i];
            int j = i + 1 + lowbit(i + 1);
            if (j < this->length) fewick_tree[j] += this->fewick_tree[i + 1]; 
        }
        this->original = nums;
    }
    
    int getsum(int ed){
        int res = 0;
        ed += 1;
        while (ed >= 1){
            res += this->fewick_tree[ed];
            ed -= lowbit(ed);
        }
        return res;
    }
    void update(int index, int val) {
        index += 1;
        int up_diff = val - original[index - 1];
        original[index - 1] = val;
        while (index < this->length){
            fewick_tree[index] += up_diff;
            index += lowbit(index);    
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return getsum(right);
        return getsum(right) - getsum(left-1);
    }
private:
    int * fewick_tree;
    int length;
    vector<int> original;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */