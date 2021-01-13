class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = 0;
        int index2 = 0;
        if (n == 0)
            return;
        int orgsize = nums1.size();
        if (m == 0){
            nums1 = nums2;
            nums1.resize(orgsize);
        }
        while (index2 < n) {
            if (index1 == m) {
                break;
            }
            if (nums1[index1] < nums2[index2]) {
                    index1++;
            }else{
                nums1.insert(nums1.begin()+index1,nums2[index2]);
                m++;
                index2++;
            }
        }
        for (int i = index2; i < n; i++){
            nums1[i-index2+m] = nums2[i];
        }
        nums1.resize(orgsize);
        //for (int i = n+m; i < orgsize; i++){
        //    nums1[i] = 0;
        //}
    }
};