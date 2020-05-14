#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int tmp = -1;
        string dic = "";
        for (int i = 0; i < path.size();i++){
            if (tmp == -1 && path[i] == '/'){
                dic="";
                tmp = i;
            }else if (path[i] == '/'){
                if (dic =="."){
                    tmp = i;
                    dic="";
                    continue;
                }
                if (dic == ".."){
                    if (!(st.empty()))
                        st.pop();
                }else{
                    if (dic != "")
                        st.push(dic);
                }
                tmp = i;
                dic="";
            }else{
                dic+=path[i];
                if (i == path.size()-1){
                    if (dic == ".."){
                        if (!st.empty())
                            st.pop();
                    }else if (dic != "." && dic !=""){
                        st.push(dic);
                    }
                }
            }
        }
        
        string answer = "";
        while (!st.empty()){
            string now = st.top();
            if (now == ""){
                st.pop();
                continue;
            }
            if (answer == "")
                answer = now  + answer;
            else
                answer = now + "/" +answer;
            st.pop();
        }
        answer = "/"+answer;
        return answer;
    }
};
int main(){
    Solution s;
    cout<<s.simplifyPath("/a//b////c/d//././/..")<<endl;
}