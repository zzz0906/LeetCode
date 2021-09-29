#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
void dfs(int i, bool & why){
    if (i == 5){
        why = true;
        return;
    }else{
        dfs(i-1,why);
        return;
    }
}
int main(){
    // unordered_map<char, int> letterCnt;
    // letterCnt['a'] = 1;
    // cout<<letterCnt['c']<<endl;
    // cout<<++letterCnt['b']<<endl;
    // string s = "abcd";
    // cout<<s.substr(s.length()-2,2)<<endl;
    // vector<int> test;
    // test.push_back(1);
    // test.push_back(2);
    // test.push_back(3);
    // vector<int>::const_iterator tmpf = test.begin()+2;
    // vector<int>::const_iterator tmpe = test.end();
    // vector<int> newv(tmpf, tmpe);
    // cout<<newv.size()<<endl;
    //set<string> colle;
    //colle.insert("f");
    // int length = 10;
    // int* a = new int[length];
    // a[0] = 1;
    // cout<<a[9]<<endl;
    // int arr[] = { 37, 37, 37, 21, 30 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    
    // vector<int> vect(arr, arr + n);
    // vector<int> vect2(arr, arr + n);
    // sort(vect2.begin(), vect2.end());
    // cout<<lower_bound(vect2.begin(), vect2.end(),vect[3]) - vect2.begin();
    bool why = false;
    dfs(10,why);
    cout << why << endl;
    vector<vector<int> > a;
    a.push_back({1,2});
    unordered_map<pair<int,int>, bool, pair_hash> records;

    cout <<"hello world" << endl;
    // vector<int> t, res(10);
    // cout<<t.size()<<endl;
    //cout<<tmp.size()<<endl;
}