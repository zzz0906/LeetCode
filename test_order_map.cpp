#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<char, int> letterCnt;
    letterCnt['a'] = 1;
    cout<<letterCnt['c']<<endl;
    cout<<++letterCnt['b']<<endl;
}