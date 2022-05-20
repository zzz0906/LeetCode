class Solution {
public:
    Solution(vector<int> w) {
        sum = w;
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back();
        return upper_bound(sum.begin(), sum.end(), x) - sum.begin();
    }
    
private:
    vector<int> sum;
};