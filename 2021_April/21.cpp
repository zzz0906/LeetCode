class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> last(0,triangle.size());
        last[0] = triangle[0][0];
        int last_size = 1;
        for (int i = 1; i < triangle.size(); i++){
            vector<int> tmp(0,triangle[i].size());
            for (int j = 0; j < triangle[i].size(); j++){
                tmp[j] = triangle[i][j];
                if (j >= 0 && j < last_size)
                    tmp[j] = tmp[j] + last[j];
                if (j - 1 >= 0 && j - 1 < last_size)
                    tmp[j] = min(tmp[j], triangle[i][j] + last[j-1]);
            }
            last_size = triangle[i].size();
            for (int j = 0; j < last_size; j ++)
                last[j] = tmp[j];
        }
        int res = INT_MAX;
        for (int i = 0; i < triangle.size(); i++){
            res = min(res,last[i]);
        }
        return res;
    }
};