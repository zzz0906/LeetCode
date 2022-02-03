class Solution {
public:
    Solution(vector<int>& nums) {
        int index = 0;
        for (auto num: nums){
            v2index[num].push_back(index);
            index++;
        }
    }
    
    int pick(int target) {
        return v2index[target][rand() % v2index[target].size()]; 
    }
    
    unordered_map<int,vector<int> > v2index;
};
int main() {
    Solution s;
    
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */