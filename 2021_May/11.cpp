class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> prefix_sum;
        k = cardPoints.size() - k;
        int res = INT_MIN;
        int left = 0;
        int tmp = 0;
        for (int i = 0; i < cardPoints.size(); i++){
            tmp += cardPoints[i];
            prefix_sum.push_back(tmp);
        }
        if (k == 0){
            return prefix_sum[prefix_sum.size() - 1];
        }
        while (left <= cardPoints.size() - k){
            int right = left + k - 1;
            
            res = max(res, prefix_sum[left] - cardPoints[left] + prefix_sum[prefix_sum.size() - 1] - prefix_sum[right]);
            cout << prefix_sum[prefix_sum.size() - 1] - prefix_sum[right] << endl;
            left += 1;
        }
        return res;
    }
};