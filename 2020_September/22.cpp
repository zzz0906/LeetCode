class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0;
        for (int i : nums){
            if (i == a) cnt1++;
            else if (i == b) cnt2++;
            else if (cnt1 == 0) {a = i; cnt1 = 1;}
            else if (cnt2 == 0) {b = i; cnt2 = 1;}
            else {cnt1--;cnt2--;}
        }
        cnt1 = 0, cnt2 = 0;
        for (int i : nums){
            if (i == a) cnt1++;
            if (i == b) cnt2++;
        }      
        vector<int> res;
        if (cnt1 > nums.size()/3) res.push_back(a);
        if (cnt2 > nums.size()/3 && b != a) res.push_back(b);
        return res;
    }
};