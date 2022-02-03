class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int cur[2] = {0,0};
        int edir = 0;
        int t = 4;
        while (t-- > 0){
            for (int i = 0; i < instructions.length(); i++){
                if (instructions[i] == 'G'){
                    cur[0] += dir[edir][0];
                    cur[1] += dir[edir][1];
                }else if (instructions[i] == 'R')
                    edir = (edir+1) % 4;
                else edir = (edir - 1 + 4) % 4;
            }
            if (cur[0] == 0 && cur[1] == 0 && edir == 0){
                return true;
            }
        }
        return false;
    }
};