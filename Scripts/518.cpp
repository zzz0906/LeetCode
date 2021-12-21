class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //inital dp
        vector<int> f(5003, 0);
        
        f[0] = 1;
        //iterate !!:pay attention to we put the coins in the outer loop
        //because each coin can only update amount once 
        for (int j = 0; j < coins.size(); j++)
            //use coins to update amount >= coins
            for (int i = coins[j]; i <= amount; i++){
                //accumulate the past result
                f[i] += f[i - coins[j]];
            }
        return f[amount];
    }
};