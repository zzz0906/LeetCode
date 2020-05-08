#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int answer[2000][2000];
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.size() == 0)
            return 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                answer[i][j] = 10000;
        answer[0][0] = grid[0][0];
        for (int i = 0; i <grid.size(); i++)
            for (int j = 0; j <grid[i].size(); j++){
                if (i == 0 && j == 0)
                    continue;
                if (i == 0){
                    answer[i][j] = answer[i][j-1] + grid[i][j];
                    continue;
                }
                if (j == 0){
                    answer[i][j] = answer[i-1][j] + grid[i][j];
                    continue;
                }
                answer[i][j] = min(answer[i-1][j], answer[i][j-1]) + grid[i][j];
            }
        return answer[grid.size()][grid[0].size()];
    }
};