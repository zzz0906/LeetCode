#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans(n, vector<int>(n));
    int dir = 2, x = 0, y = 0;
    int max_x = n - 1, max_y = n - 1;
    int min_x = 0, min_y = 1;
    int i = 0;
 
    while (++i <= n*n) {
      ans[y][x] = i;
      switch (dir) {
        // up
        case 1: if (--y == min_y) { dir = 2; ++min_y; } break;
        // right
        case 2: if (++x == max_x) { dir = 3; --max_x; } break;
        // down
        case 3: if (++y == max_y) { dir = 4; --max_y; } break;
        // left
        case 4: if (--x == min_x) { dir = 1; ++min_x; } break;
      }
    }
 
    return ans;
  }
};