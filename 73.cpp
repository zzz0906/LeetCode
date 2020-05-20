class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        if (matrix.size() == 1 && matrix[0].size() == 1)
            return;
        int flagx = -1;
        int flagy = -1;
        bool flag = false;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == 0){
                    if (flag == false){
                        flag = true;
                        flagx = i;
                        flagy = j;
                        matrix[flagx][flagy] = -1;
                    }
                    else{
                        matrix[i][flagy] = -1;
                        matrix[flagx][j] = -1;
                    }
                }
            }
        }
        for (int i = 0; i<matrix.size(); i++)
            if (i != flagx && matrix[i][flagy] == -1){
                for (int j = 0; j<matrix[i].size(); j++)
                    if (j != flagy)
                        matrix[i][j] = 0;
            }
        cout<<matrix[0][3];
        for (int j = 0; j<matrix[0].size(); j++)
            if (j != flagy && matrix[flagx][j] == -1){
                for (int i = 0; i<matrix.size(); i++)
                    if (i != flagx){
                        matrix[i][j] = 0;
                    }
            }
        for (int j = 0; j<matrix[0].size(); j++)
            matrix[flagx][j] = 0;
        for (int j = 0; j<matrix.size(); j++)
            matrix[j][flagy] = 0;
    }
};