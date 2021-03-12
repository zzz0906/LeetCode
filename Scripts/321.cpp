class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > records_1;
        vector<vector<int> > records_2;
        for (int i = 0; i <= 9; i++){
            vector<int> tmp;
            records_1.push_back(tmp);
        }
        for (int i = 0; i <= 9; i++){
            vector<int> tmp;
            records_2.push_back(tmp);
        }

        for (int i = 0; i < nums1.size(); i++)
            records_1[nums1[i]].push_back(i);
        for (int i = 0; i < nums2.size(); i++)
            records_2[nums2[i]].push_back(i);
        vector<int> answer;
        int rest1 = nums1.size();
        int rest2 = nums2.size();
        while (answer.size() < k){
            int st = 9;
            while (true){
                if (records_1[st].size() != 0){
                    for (int i = 0; i < records_1[st].size(); i++)
                        if (records_1[st][i] >= nums1.size() - rest1 && nums1.size() - records_1[st][i] - 1 + rest2 >= k - answer.size()){
                        rest1 = nums1.size() - records_1[st][i] - 1;
                        records_1[st].erase(records_1[st].begin(),records_1[st].begin() + i);
                        answer.push_back(st);
                        break;
                        }
                }
                
                st --;
            }
        }
    }
};