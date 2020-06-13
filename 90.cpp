class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> answer; 
    vector<int> input_nums;
    int bucket[100000];
    void dfs(int index){
    //reach the end
        if (index == input_nums.size()){
            answer.push_back(tmp);
            return;
        }
        bool last_round_flag = false; 
        int tmpindex =index;
        if (index > 0 && input_nums[index-1] == input_nums[index]){
            if (bucket[index-1] == 0){
                dfs(index+1);
            }else{
                bucket[index] = 1;
                tmp.push_back(input_nums[index]);
                dfs(index+1);
                tmp.pop_back();
                bucket[index] = 0;
                // Not Contain This Element
                dfs(index+1);
            }
        }
        else{
            bucket[index] = 1;
            tmp.push_back(input_nums[index]);
            dfs(index+1);
            tmp.pop_back();
            bucket[index] = 0;
            // Not Contain This Element
            dfs(index+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(bucket,0,sizeof(bucket));
        input_nums = nums;
        dfs(0);
        return answer;
    }
};