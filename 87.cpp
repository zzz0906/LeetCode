#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0)
            return true;
        bool stackflag = false;
        string stack1= "";
        string stack2= "";
        int index1 = 0;
        while (index1 < s1.size()){
            cout<<index1<<endl;
            if (s1[index1] != s2[index1] && stackflag){
                stack1 = s1[index1];
                stack2 = s2[index1];
                stackflag = false;
                index1++;
            }else if (stackflag == false){
                if (stack1[0] == s2[index1]){
                    //compare
                    stack1 += s1[index1];
                    stack2 += s2[index1];
                    reverse(stack1.begin(), stack1.end());
                    if (stack1 != stack2) return false;
                    stackflag = true;
                    stack1 = "";
                    stack2 = "";
                    index1++;
                }else{
                  stack1 += s1[index1];
                  stack2 += s2[index1];
                  index1++;  
                }
            }else index1++;
        }
        return stackflag;
    }
};