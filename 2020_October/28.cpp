class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        int last = nums[0];
        int st = nums[0];
        int ed = nums[0];
        for (int i = 1; i < nums.size(); i++)
            if (last == nums[i] || last == nums[i]-1){
                ed = nums[i];
                last = nums[i];
            }else{
                //cout<<st<<ed<<endl;
                string tmp;
                if (st != ed)
                    tmp = to_string(st) + "->" + to_string(ed);
                else
                    tmp = to_string(st);
                ans.push_back(tmp);
                last = nums[i];
                st = nums[i];
                ed = nums[i];
            }
        string tmp;
        if (st != ed)
            tmp = to_string(st) + "->" + to_string(ed);
        else
            tmp = to_string(st);
        ans.push_back(tmp);
        return ans;
    }
};