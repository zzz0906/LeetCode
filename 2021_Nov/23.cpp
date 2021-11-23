class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        // 1. store the map from factors -> the size of component
        int res = 0;
        vector<int> count;
        vector<int> disjointset;
        vector<int> setLabel;
        for (auto num : nums){
            // 1. factorize num
            vector<int> factors;
            //1 <= nums[i] <= 10^5
            if (num % 2 == 0){
                factors.push_back(2);
            }
            while (num % 2 == 0)
            {
                cout << 2 << " ";
                num = num/2;
            }
 
            // n must be odd at this point. So we can skip
            // one element (Note i = i +2)
            for (int i = 3; i <= sqrt(num); i = i + 2)
            {
                // While i divides n, push i and divide n
                if (num % i == 0){
                    factors.push_back(i);
                }
                while (num % i == 0)
                {
                    num = num/i;
                }
            }
            if (num > 2){
                factors.push_back(num);
            }

            // iterate all factors key set to insert to the disjoint set
            bool find = false;
            for (int i = 0; i < disjointset.size(); i++){
                // determine current element's factor belongs to one of the disjoint set
                for (auto fac : factors){
                    if (disjointset[i] % fac == 0){
                        find = true;
                        break;
                    }
                }
                if (find){

                    count[i] ++;

                    // update the new disjoint relationship because we add this new element
                    for (int j = 0; j < disjointset.size(); j++){
                        if (j != i){
                            bool update = false;
                            for (auto fac : factors){
                                if (j != i && disjointset[j] % fac == 0){
                                    update = true;
                                    break;
                                }
                            }
                            disjointset[j] = i;
                        }
                    }

                    break;
                }
            }
            if (!find){
                // new no joint factors
                int keyfact = 1;
                for (auto fac : factors){
                    keyfact *= fac;
                }
                count.push_back(1);
                disjointset.push_back(keyfact);
                setLabel.push_back(setLabel.size());
            }
        }

        // find the biggest answer
        int res = 0;
        vector<bool> whetherAccess(disjointset.size(), true);
        for (int i = 0; i < disjointset.size(); i++){
            if (whetherAccess[i]){
                int oneRoundCount = 0;
                int start = i;
                while (disjointset[start] != start){
                    whetherAccess[start] = false;
                    oneRoundCount += count[start];
                    start = disjointset[start];
                }
                oneRoundCount += disjointset[start];
                res = max(res, oneRoundCount);
            }
        }
        
        return res;
    }
};