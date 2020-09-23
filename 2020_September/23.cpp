class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for (int i = 0; i < gas.size(); i++)
            diff.push_back(gas[i] - cost[i]);
        //-1 3 5 2
        for (int i = 0; i < diff.size(); i++){
            int cur = i;
            int cur_sum = 0;
            while (cur_sum >= 0){
                cur_sum += diff[cur];
                if (cur + 1 < diff.size()){
                    cur = cur + 1;
                }else{
                    cur = 0;
                }
                if (cur == i && cur_sum >= 0) return i;
            }
        }
        return -1;      
    }
};