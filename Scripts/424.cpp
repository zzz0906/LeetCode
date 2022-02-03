class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<vector<int>> prefix_sum(1, vector<int>(26,0));
        prefix_sum[0][s[0] - 'A'] += 1;
        //o(n)
        for (int i = 1; i < s.length(); i++){
            prefix_sum.push_back(prefix_sum[i-1]);
            prefix_sum[i][s[i] - 'A'] += 1;
        }
        //binary search answer
        int res = 0;
        int left = 1;
        int right = s.length();
        while (left < right - 1){
            int mid = left + (right - left) / 2;
            bool find = false;
            for (int i = 0; i < s.length() - mid + 1; i++){
                vector<int> cur_left = prefix_sum[i];
                vector<int> cur_right = prefix_sum[i + mid - 1];
                cur_right[s[i] - 'A'] += 1;
                int tmpmax = INT_MIN;
                for (int j = 0; j < cur_left.size(); j++) {
                    cur_right[j] -= cur_left[j];
                    tmpmax = max(cur_right[j], tmpmax);
                }
                if (mid - tmpmax <= k){
                    res = max(res,mid);
                    find = true;
                    break;
                }
            }
            if (find){
                left = mid;
            }else{
                right = mid;
            }
        }

        int mid = right;
        bool find = false;
        for (int i = 0; i < s.length() - mid + 1; i++){
            vector<int> cur_left = prefix_sum[i];
            vector<int> cur_right = prefix_sum[i + mid - 1];
            cur_right[s[i] - 'A'] += 1;
            int tmpmax = INT_MIN;
            for (int j = 0; j < cur_left.size(); j++) {
                cur_right[j] -= cur_left[j];
                tmpmax = max(cur_right[j], tmpmax);
            }
            if (mid - tmpmax <= k){
                res = max(res,mid);
                find = true;
                break;
            }
        }

        return res;
    }
};