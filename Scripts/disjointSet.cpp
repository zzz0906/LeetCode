# include <bits/stdc++.h>
using namespace std;
class disjointSet{
    private:
        vector<int> setArray;
    public:
        disjointSet(int maxLength){
            vector<int> tmp(maxLength + 1);
            setArray = tmp;
        }
        int modify(int x, int y){
            setArray[findRoot(x)] = setArray[findRoot(y)];
        }
        int findRoot(int x) {
            return setArray[x] == x ? x : (setArray[x] = findRoot(setArray[x]));
        }
}