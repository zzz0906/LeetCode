class Solution {
public:
    bool dfs (int l1, int l2, int l3, int l4, int target, int index, vector<int> &matchsticks){
        if (index == matchsticks.size()){
            if (l1 == target && l2 == target && l3 == target && l4 == target)
                return true;
            return false;
        }
        if (l1 + matchsticks[index] <= target){
            if (dfs(l1 + matchsticks[index],l2,l3,l4,target,index + 1, matchsticks)){
                return true;
            }
        }
        if (l2 + matchsticks[index] <= target){
            if (dfs(l1,l2 + matchsticks[index],l3,l4,target,index + 1, matchsticks)){
                return true;
            }
        }
        if (l3 + matchsticks[index] <= target){
            if (dfs(l1,l2,l3 + matchsticks[index],l4,target,index + 1, matchsticks)){
                return true;
            }
        }
        if (l4 + matchsticks[index] <= target){
            if (dfs(l1,l2,l3,l4 + matchsticks[index],target,index + 1, matchsticks)){
                return true;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;
        
        int len = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return dfs(0,0,0,0,len,0,matchsticks);
    }
};