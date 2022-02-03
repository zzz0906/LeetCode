class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        vector<int>::iterator it = nums1.begin
        while (p1 < m && p2 < n) {
            if (nums1[p1] < nums2[p2])
                p1++;
            else{
                nums1.insert(it+p1,nums2[p2]);
                p2++;
                p1++;
                m++;
            }
        }
        while (p2 < n){
            nums1.insert(it+p1,nums2[p2]);
            p2++;
            p1++;
            m++;
        }
    }
};