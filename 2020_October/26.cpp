class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        before = 0;
        for (int i = 1; i <= query_row + 1 - 1; i++)
            before += i;
        if (poured - before <= 0) return 0;
        poured -= before;
        query_row = query_row + 1
        query_glass = query_glass + 1;
        if (query_row == 1){
            if (poured > 1) return 1;
            else return poured;
        }
        if (query_glass == 1 || query_glass == query_row){
            int tmp = poured/(2*query_row-2);
            if (tmp < 1) return tmp; else return 1;
        }
        else{
            int tmp =  poured/(query_row-1);
            if (tmp < 1) return tmp; else return 1;
        }
    }
};