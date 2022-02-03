class Solution {
public:
    int type_bucket[200003];
    int distributeCandies(vector<int>& candyType) {
        for (int i = 0; i < 200003; i++)
            type_bucket[i] = 0;
        for (int i = 0; i < candyType.size();i++)
            type_bucket[candyType[i] + 100000] = 1;
        int max_n = candyType.size() / 2;
        for (int i = 0; i < 200003; i++){
            if (type_bucket[i] == 1)
                max_n --;
            if (max_n == 0) return candyType.size() / 2;
        }
        return candyType.size() / 2 - max_n;

    }
};