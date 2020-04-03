#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        string tmp;
        vector<int> answer;
        std::map<std::string, int> borrow_words;
        for (int j = 0; j < words.size(); j++){
            if (borrow_words.count(words[j]) == 0)
                borrow_words.insert(std::make_pair(words[j],1));
            else
                borrow_words[words[j]] ++;
        }
        if (s.compare("") == 0)
            return answer;
        if (words.size() == 0)
            return answer;
        int arbi_length = words.size() * words[0].size();
        for (int i = 0; i < s.size();i++){
            tmp = "";
            if (i + arbi_length <= s.length())
                tmp = s.substr(i, arbi_length);        
            std::map<std::string, int> tmpw = borrow_words;
            bool flag = true;
            if (tmp != ""){
                int st = 0;
                while (st < tmp.length()){
                    string now = tmp.substr(st,words[0].size());
                    st = st + words[0].size();
                    bool tmpflag = false;
                    int index = 0;
                    if (tmpw.count(now) == 1){
                        map<string,int>::iterator key = tmpw.find(now);
                        tmpflag = true;
                        if (tmpw[now] > 1)
                            tmpw[now] --;
                        else tmpw.erase(key);
                    }
                    else {
                        flag = false;
                        break;
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