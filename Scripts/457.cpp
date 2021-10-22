class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        vector<bool> beenTo(nums.size(), false);
        for (int i = 0; i < nums.size(); i++){
            
            if (!beenTo[i] && nums[i] != 0){
                int pOrN = nums[i] > 0 ? true : false;
                int find = true;
                vector<bool> thisRound(nums.size(), false);
                
                int last = i;
                thisRound[last] = true;
                beenTo[last] = true;
        
                int cur = nums[i] > 0 ? (i + nums[i]) % nums.size() : (i + nums[i] < 0 ? i + nums[i] + nums.size() : i + nums[i]) % nums.size();
                
                if (cur == last){
                    continue;
                }
                
                while (!thisRound[cur]){
                    
                    thisRound[cur] = true;
                    beenTo[cur] = true;
                    
                    int next = nums[cur] > 0 ? (cur + nums[cur]) % nums.size() : (cur + nums[cur] < 0 ? cur + nums[cur] + nums.size() : cur + nums[i]) % nums.size();
                    if (nums[cur] == 0 || next == cur){
                        find = false;
                        break;
                    }
                    
                    bool curPorN;
                    if (nums[cur] < 0){
                        curPorN = false;
                    }else{
                        curPorN = true;
                    }
                    if (curPorN != pOrN){
                        find = false;
                        break;
                    }
                    
                    cur = next;
                }
                
                if (find){
                    return true;
                }
            }
        }
        return false;
    }
};