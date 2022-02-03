class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        for (int i = 0; i < matrix.size(); i++) {
            if (target < matrix[i][0] || target > matrix[i][matrix[i].size()-1])
                continue;
            int st = 0;
            int ed = matrix[i].size()-1;
            int tmp = 0;
            while (st <= ed){
                tmp = (st+ed)/2;
                if (matrix[i][st] == target || matrix[i][ed] == target || matrix[i][tmp] == target) return true;
                if (ed - st <= 1) break;
                if (target >= matrix[i][tmp]) st = tmp;
                else ed = tmp;
            }
        }
        return false;    
    }
};