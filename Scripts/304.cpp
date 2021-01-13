class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++){
            int tmp = 0;
            vector<int> tmp_v; tmp_v.push_back(0);
            for (int j = 0; j < matrix[i].size(); j++){
                tmp += matrix[i][j];
                tmp_v.push_back(tmp);
            }
            this->row_prefix_matrix.push_back(tmp_v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; i++)
            ans += row_prefix_matrix[i][col2+1] - row_prefix_matrix[i][col1];
        return ans;
    }
private:
    vector<vector<int> > row_prefix_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */