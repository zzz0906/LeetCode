class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int mn = INT_MAX;
        for (int i = A.size() - 1; i >=2; i--){
            mn = min(mn,A[i]);
            if (A[i-2] > mn) return false;
        }
        return true;
    }
};