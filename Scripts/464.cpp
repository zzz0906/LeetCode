class Solution {
public:
    unordered_map<int, bool> mem;
    bool choose(int choosen, int cur, int maxC, int target){
        if (mem.count(choosen))
            return mem[choosen];
        for (int i = 0; i < maxC; i++){
            if ( ((choosen >> i) & 1) == 0 && cur + i + 1 >= target){
                mem[choosen] = true;
                return true;
            }
        }

        for (int i = 0; i < maxC; i++)
            if (((choosen >> i) & 1) == 0){
                bool nextwin = choose(choosen | (1 << i), cur + i + 1, maxC, target);
                if (!nextwin){
                    mem[choosen] = true;
                    return true;
                }
                if (mem.count(choosen))
                    return mem[choosen];
            }

        mem[choosen] = false;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal){
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if ((1 + maxChoosableInteger)* maxChoosableInteger / 2 < desiredTotal)
            return false;
        return choose(0, 0, maxChoosableInteger, desiredTotal);
    }
};