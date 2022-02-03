class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int splitBuckets = ceil ( (double) buckets / ((int) (minutesToTest / minutesToDie)));
        int res = ceil( - (log( 1 / (double) splitBuckets) / log(2)) );
        return res;
    }
};