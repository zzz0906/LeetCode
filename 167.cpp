class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //int pos = lower_bound(numbers,numbers+numerbs.size(),target)-numbers;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++){
            int tmptarget = target - numbers[i];
            int pos = lower_bound(numbers.begin()+i+1,numbers.end(),tmptarget)-numbers.begin();
            if (numbers[pos] == tmptarget){
                res.push_back(i+1);
                res.push_back(pos+1);
                return res;
            }
        }
        return res;
    }
};