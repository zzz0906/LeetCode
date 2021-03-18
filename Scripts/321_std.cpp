class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int i = max(0, k - n2); i <= min(k, n1); ++i)
            ans = max(ans, maxNumber(maxNumber(nums1, i), 
                                     maxNumber(nums2, k - i)));
        return ans;
    }
private:    
    vector<int> maxNumber(const vector<int>& nums, int k) {
        vector<int> ans(k);                
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j > 0 && nums[i] > ans[j - 1] 
                   && nums.size() - i > k - j) --j;
            if (j < k) ans[j++] = nums[i];
        }
        return ans;
    }
    
    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans(nums1.size() + nums2.size());
        auto s1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto s2 = nums2.cbegin();
        auto e2 = nums2.cend();        
        int index = 0;
        while (s1 != e1 || s2 != e2)
            ans[index++] = 
              lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++; // so clear first * then ++
        return ans;
    }
};