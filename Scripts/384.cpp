class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        srand((unsigned)time(NULL)); 
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        vector<int> choose;
        for (int i = 0; i < original.size(); i++)
            choose.push_back(i);
        int length = original.size();

        srand((unsigned)time(NULL));
        sleep(100);
        for (int i = 0; i < original.size(); i++){
            int cur = rand() % length;
            res.push_back(original[choose[cur]]);
            if (cur != length - 1)
                swap(choose[cur],choose[length - 1]);
            length --;
        }
        return res;
    }
    private:
        vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */