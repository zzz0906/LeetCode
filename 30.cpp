#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        string tmp;
        vector<int> answer;
        if (s.compare("") == 0)
            return answer;
        if (words.size() == 0)
            return answer;
        int arbi_length = words.size() * words[0].size();
        for (int i = 0; i < s.size();i++){
            tmp = "";
            if (i + arbi_length <= s.length())
                tmp = s.substr(i, arbi_length);
            vector<string> tmpw = words;
            bool flag = true;
            if (tmp != ""){
                int st = 0;
                while (st < tmp.length()){
                    string now = tmp.substr(st,words[0].size());
                    st = st + words[0].size();
                    bool tmpflag = false;
                    int index = 0;
                    for (int j = 0; j < tmpw.size();j++){
                        if (tmpw[j].compare(now) == 0){
                            tmpflag = true;
                            index = j;
                            break;
                        }
                    }
                    if (tmpflag == false){
                        flag = false;
                        break;
                    }else{
                        tmpw.erase(tmpw.begin()+index);
                        continue;
                    }
                }
                if (flag == true){
                    answer.push_back(i);
                }
            }
        }
        return answer;
    }
};