#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        vector<int> onedim;
        for (int i = 0; i < matrix.size();i++)
            for (int j = 0; j < matrix[i].size(); j++)
                onedim.push_back(matrix[i][j]);
        return binary_search(onedim.begin(), onedim.end(),target);
    }
};