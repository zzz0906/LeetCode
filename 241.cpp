class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> answer;
        if (input.length() == 0) return answer;
        if ((input.find("+") == std::string::npos) && (input.find("-") == std::string::npos) && (input.find("*") == std::string::npos)){
            answer.push_back(stoi(input));
            return answer;
        }
        for (int i = 0; i < input.size(); i++)
            if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> cu1,cu2;
                switch (input[i]){
                    case '+':
                        cu1 = diffWaysToCompute(input.substr(0,i));
                        cu2 = diffWaysToCompute(input.substr(i+1,input.size()- (i + 1) + 1));
                        for (int i = 0; i < cu1.size(); i++)
                            for (int j = 0; j < cu2.size(); j++)
                                answer.push_back(cu1[i] + cu2[j]);
                        break;
                    case '-':
                        cu1 = diffWaysToCompute(input.substr(0,i));
                        cu2 = diffWaysToCompute(input.substr(i+1,input.size()- (i + 1) + 1));
                        for (int i = 0; i < cu1.size(); i++)
                            for (int j = 0; j < cu2.size(); j++)
                                answer.push_back(cu1[i] - cu2[j]);
                        break;
                    default:
                        cu1 = diffWaysToCompute(input.substr(0,i));
                        cu2 = diffWaysToCompute(input.substr(i+1,input.size()- (i + 1) + 1));
                        for (int i = 0; i < cu1.size(); i++)
                            for (int j = 0; j < cu2.size(); j++)
                                answer.push_back(cu1[i] * cu2[j]);

                }
            }
        return answer;
    }
};