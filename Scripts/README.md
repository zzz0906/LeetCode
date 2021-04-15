class Solution {
public:
    template <typename A, typename B>multimap<B, A> flip_map(map<A,B> & src) {

        multimap<B,A> dst;

        for(typename map<A, B>::const_iterator it = src.begin(); it != src.end(); ++it)
            dst.insert(pair<B, A>(it -> second, it -> first));
        
        return dst;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> count_t;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            if (count_t.count(nums[i]))
                count_t[nums[i]] += 1;
            else
                count_t[nums[i]] = 1;
        }
        multimap<int, int> reverseTest = flip_map(count_t);
        int count_k = 0;
        for(multimap<int, int>::const_reverse_iterator it = reverseTest.rbegin(); it != reverseTest.rend(); ++it){
            res.push_back(it->second);
            count_k ++;
            if (count_k == k) break;
        }
        return res;
    }
};