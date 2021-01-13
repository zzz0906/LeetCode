class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if (numRows == 0) return answer;
        vector<int> tmp;
        tmp.push_back(1);
        answer.push_back(tmp);
        if (numRows == 1) return answer;
        tmp.push_back(1);
        answer.push_back(tmp);
        for (int i = 2; i < numRows;i++){
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 0; j < answer[i-1].size()-1;j++)
                tmp.push_back(answer[i-1][j]+answer[i-1][j+1]);
            tmp.push_back(1);
            answer.push_back(tmp);
        }
        return answer;
    }
};