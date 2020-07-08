class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex+1;
        vector<vector<int>> answer;
        vector<int> tmp;
        tmp.push_back(1);
        if (rowIndex == 0) return tmp;
        answer.push_back(tmp);
        tmp.push_back(1);
        answer.push_back(tmp);
        if (rowIndex == 1) return tmp;
        for (int i = 2; i < numRows;i++){
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 0; j < answer[i-1].size()-1;j++)
                tmp.push_back(answer[i-1][j]+answer[i-1][j+1]);
            tmp.push_back(1);
            answer.push_back(tmp);
        }
        return answer[rowIndex];
    }
};