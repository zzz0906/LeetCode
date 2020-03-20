#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool valid(string temp){
        int stack_b[100];
        for (int i = 0; i < 100; i++)
            stack_b[i] = 0;
        int index_now = 0;
        for (int i = 0; i < temp.size(); i++){
            if (temp[i] == ')'){
                if (index_now == 0 || stack_b[index_now-1] == 0)
                    return false;                
                index_now--;
            }else{
                stack_b[index_now] = 1;
                index_now ++;
            }
        }
        if (index_now > 0) return false;
        return true;
    }
    void checkanswer(string temp){
        for (int i = 0; i < answer.size();i++)
            if (answer[i] == temp) return;
        //cout<<temp<<endl;
        answer.push_back(temp);    
    }
    vector<string> answer;
    void dfs(int now,string now2){
        if (valid(now2) == false)
            return;
        if (now == 0){
            checkanswer(now2);
            return;
        }
        for (int i = 0; i < now2.size(); i++){
            for (int j = i; j < now2.size(); j++){
                string tmp = now2;
                tmp.insert(i,"(");
                tmp.insert(j,")");
                dfs(now-1,tmp);
            }
            string tmp = now2;
            tmp.insert(i,"(");
            dfs(now-1,tmp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp[1] = {"()"};
        vector<string> fi(tmp,tmp+1);
        if (n == 1)
            return fi;
        dfs(n-1,"()");   
        return this->answer;
    }
};
int main(){
	Solution s;
    s.generateParenthesis(3);
}
