class Solution {
public:
    int nums;
    int target;
    vector<vector<int>> answer;
    void dfs(int last, int current, int k, vector<int> tmp){
        if (current > target) return;
        if (k == nums - 1){
            if (target - current <= last) return;
            if (target - current > 9) return;
            tmp.push_back(target - current);
            answer.push_back(tmp);
            return;
        }
        for (int i = last+1; i <= 9; i++){
            vector<int> tmptmp = tmp;
            tmptmp.push_back(i);
            if (current + 2*i > target) break;
            dfs(i,current+i,k+1,tmptmp);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        target = n;
        nums = k;
        vector<int> tmp;
        dfs(0,0,0,tmp);
        return answer;
    }
};