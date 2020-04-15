#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> tmp;
    vector<int> gl_candidates;
    int gl_target;
    vector<vector<int> > answer;
    void dfs(int index,int sum){
        if (sum == gl_target){
            vector<int> tmpanswer = tmp;
            sort(tmpanswer.begin(),tmpanswer.end());
            if (find(answer.begin(),answer.end(),tmpanswer) == answer.end())
                answer.push_back(tmpanswer);
            return;
        }
        if (index == gl_candidates.size())
            return;
        if (sum > gl_target)
            return;
        tmp.push_back(gl_candidates[index]);
        dfs(index+1,sum+gl_candidates[index]);
        tmp.pop_back();
        dfs(index+1,sum);
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        gl_candidates = candidates;
        gl_target = target;
        dfs(0,0);
        return answer;
    }
};
int main(){
    Solution s;
    int a[7] = {10,1,2,7,6,1,5};
    vector<int> candidates(a,a+6);
    s.combinationSum2(candidates,8);
}