# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //store the flag whether we reach this node.
    vector<bool> nodes;
    //store the count of 0 index
    int count;
    void dfs(int index, vector<int>& arr){
        // when we reac this index
        nodes[index] = true;
        // if it's zero just return it
        if (arr[index] == 0){
            count ++;
            return;
        }
        // + index not out of range and + index we never been to
        if (index + arr[index] < arr.size() && !nodes[index + arr[index]]){
            dfs(index + arr[index], arr);
            if (count >= 1)
                return;
        }
        // - index not out of range and + index we never been to
        if (index - arr[index] >= 0 && !nodes[index - arr[index]]){
            dfs(index - arr[index], arr);
            if (count >= 1)
                return;
        }
    }
    bool canReach(vector<int>& arr, int start) {
        //init nodes records
        nodes.resize(arr.size(), false);
        //count = 0
        count = 0;
        dfs(start, arr);
        return count > 0;
    }
};