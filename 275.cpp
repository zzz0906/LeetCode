class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        for (int i = 0; i < citations.size(); ++i) {
            if (i >= citations[i]) return i;
        }

        return citations.size();
    }
};