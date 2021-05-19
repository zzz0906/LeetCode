class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        if (m.count(val)) res = false;
        
        nums.push_back(val);
        m[val].push_back(nums.size() - 1);
        
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;
        int last = nums.back();
        m[last].pop_back();
        m[last].push_back(m[val].back());
        nums[m[val].back()] = last;
        nums.pop_back();
        m[val].pop_back();
        if (m[val].size() == 0)
            m.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    private:
        vector<int> nums;
        unordered_map<int, vector<int> > m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */