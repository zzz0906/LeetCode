class Solution {
public:
    unordered_map<long long, int> countn;
    bool isHappy(int n) {
        countn.clear();
        long long tmp = n;
        while (countn.count(tmp) == 0){
            countn[tmp] = 1;
            int tmpforn = tmp;
            tmp = 0;
            //calculate last ans
            while (tmpforn != 0){
                int rem = tmpforn % 10;
                tmp += rem*rem;
                tmpforn = tmpforn / 10;
            }
            //get this round
            if (tmp == 1) return true;
        }
        return false;
    }
};