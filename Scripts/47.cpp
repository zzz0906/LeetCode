#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> tmpnums;
    vector<int> original;
    vector<int> tmp;
    vector<vector<int> > answer;
    vector<vector<int> > realanswer;
    void dfs(int layer){
        if (layer == tmpnums.size())
            {
                answer.push_back(tmp);
                return;
            }
        for (int i = 1; i < tmpnums.size()+1; i++){
            bool flag = false;
            for (int j = 0; j < layer;j++)
                if (tmp[j] == i){
                    flag = true;
                    break;
                }
            if (flag == false){
                tmp.push_back(i);
                dfs(layer+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        tmpnums = nums;
        original = nums;
        dfs(0);
        for (int i = 0; i < answer.size();i++){
            vector<int> tmp;
            for (int j = 0; j < answer[i].size();j++){
                tmp.push_back(original[answer[i][j]-1]);
                //str_tmp += '0' + original[answer[i][j]-1];
            }
            bool findse = false;
            for (int j = 0; j < realanswer.size(); j++){
                bool tmpfind = true;
                for (int k = 0; k < realanswer[j].size();k++)
                    if (realanswer[j][k] != tmp[k]){
                        tmpfind = false;
                        break;
                    }
                if (tmpfind){
                    findse = true;
                    break;
                }        
            }
            if (findse == false)
                realanswer.push_back(tmp);
        }
        return realanswer;
    }
};