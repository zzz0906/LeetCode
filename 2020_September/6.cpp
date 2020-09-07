class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A.size(); j++)
                ans = max(ans,max(current(A,B,i,j),current(B,A,i,j)));
        return ans;
    }
    int current(vector<vector<int>>& A, vector<vector<int>>& B,int rowOffset, int colOffset) {
        int sum = 0;
        for (int i = rowOffset; i < A.size();i ++) {
            for (int j = colOffset; j < A.size(); ++j) {
                sum += A[i-rowOffset][j-colOffset] * B[i][j];
            }
        }
        return sum;
    }
};