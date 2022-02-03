#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
    private:
        int pivot;
        int max_num;
        map<int,int> bits;
        int total = 0;
    public:
        int lowbit(int x) {
            return x & -x;
        }
        FenwickTree(int minn, int maxx){
            this->pivot = minn*-1 + 1;
            this->max_num = 2*maxx + this->pivot;
        }
        void update(int num, int count){
            this->total += count;

            int i = num + this->pivot;

            while (i <= this->max_num){
                this->bits[i] += count;
                i += lowbit(i);
            }
        }
        int getCount(int num){
            int i = num + this->pivot;

            int res = 0;
            while (i > 0){
                res += this->bits[i];
                i -= lowbit(i);
            }
            return res;
        }
}