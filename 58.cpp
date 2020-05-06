#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> cont;
        char delim = ' ';
        std::stringstream ss(s);
        std::string token;
        bool flag = false;
        for (int i = 0; i< s.length();i++)
            if (s[i] != ' '){
                flag = true;
                break;
            }
        if (flag == false)
            return 0;
        while (getline(ss, token, delim)) {
            cont.push_back(token);
        }
        if (cont.size() == 0)
            return 0;
        string answer;
        int i = cont.size()-1;
        while (cont[i] == " " || cont[i] == "") {
            i--;
        }
        answer = cont[i];
        return answer.length();
    }
};