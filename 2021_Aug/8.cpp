class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        // vector<vector<int>> order(matrix.size(),vector<int>(matrix[0].size(),0));
        // for (int i = 0; i < matrix.size(); i++)
        //     for (int j = 0; j < matrix.size(); j++){
        //         vector<int> tmp = matrix[i];
        //         for (int k = 0; k < matrix.size(); k++){
        //             if (k != i)
        //                 tmp.push_back(matrix[k][j]);
        //         }
        //         sort(tmp.begin(), tmp.end());
        //         lower_bound(tmp.begin(), tmp.end(),matrix[i][j]) - tmp.begin();
        //     }
        
        vector<vector<int>> res(matrix.size(),vector<int>(matrix[0].size(),-1));
        int labeld = 0, all = matrix.size()*matrix[0].size();
        
        // initialize for 1 => have some problem 
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++){
                vector<int> tmp = matrix[i];
                for (int k = 0; k < matrix.size(); k++){
                    if (k != i)
                        tmp.push_back(matrix[k][j]);
                }
                bool lessthan = false;
                for (int k = 0; k < tmp.size(); k++)
                    if (tmp[k] < matrix[i][j])
                        lessthan = true;
                if (!lessthan){
                    res[i][j] = 1;
                    labeld += 1;
                }
            }
        
        int rank = 2;
        while (labeld < all) {
            for (int i = 0; i < matrix.size(); i++)
                for (int j = 0; j < matrix[0].size(); j++)
                    if (res[i][j] == -1){
                        //row
                        // int maximum_value = INT_MIN;
                        int max_rank = -1;
                        bool unlabel = false;
                        for (int k = 0; k < matrix[0].size(); k++){
                            if (matrix[i][k] <= matrix[i][j]){
                                if (res[i][k] == -1){
                                    unlabel = true;
                                    break;
                                }
                                max_rank = max(max_rank,res[i][k]);
                            }
                        }
                        //column
                        for (int k = 0; k < matrix.size(); k++){
                            if (matrix[k][j] <= matrix[i][j]){
                                if (res[k][j] == -1){
                                    unlabel = true;
                                    break;
                                }
                                max_rank = max(max_rank,res[k][j]);
                            }
                        }

                        if (unlabel == false && max_rank + 1 == rank){
                            res[i][j] = rank;
                            labeld ++;
                        }
                    }
            rank++;
        }
        return res;
    }
};