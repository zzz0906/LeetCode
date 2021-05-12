class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int cur_n = 0;
        int p1 = 0; int p2 = 0; int cur = 0;
        while (cur_n < k){
            int choosen = nums1[cur] + nums2[p1];
            if (cur + 1 < nums1.size){
                if (choosen > nums1[cur])
            }else{
                
            }
        }
    }
};