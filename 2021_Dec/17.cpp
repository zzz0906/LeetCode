class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        
        int res = 0;
        vector<vector<int>> answer;
        
        for (int i = 0;i<matrix.size();i++){
            std::vector<int> mid;
            mid.clear();
            for (int j = 0;j<matrix[i].size();j++)
                if (matrix[i][j] == '1'){
                    mid.push_back(1);
                    res = 1;
                } else
                    mid.push_back(0);
            answer.push_back(mid);
        }
        
        for (int i = 1;i<answer.size();i++)
          for (int j =1;j<answer[i].size();j++)
            if (matrix[i][j] == '1'){
                int lastrow = j - answer[i - 1][j - 1] - 1; 
                int lastcolumn = i - answer[i - 1][j - 1] - 1;
                for (int k = j - 1; k >= j - answer[i-1][j-1]; k--)
                    if (matrix[i][k] == '0') {
                        lastrow = k;
                        break;
                    }
                lastrow = j - lastrow;
                for (int k = i - 1; k >= i - answer[i - 1][j - 1]; k--)
                    if (matrix[k][j] == '0') {
                        lastcolumn = k;
                        break;
                    }
                lastcolumn = i - lastcolumn;
                int last = min(lastcolumn,lastrow);
                answer[i][j] = max(last,answer[i][j]);
                if (answer[i][j] > res) res = answer[i][j];
            }
        return res*res;
    }
};