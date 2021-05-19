class RandomizedCollection {
public:
    RandomizedCollection() {}
    bool insert(int val) {
        m[val].push(nums.size());
        nums.push_back(val);
        return m[val].size() == 1;
    }
    bool remove(int val) {
        if (m[val].empty()) return false;
        int idx = m[val].top();
        m[val].pop();
        if (nums.size() - 1 != idx) {
            int t = nums.back();
            nums[idx] = t;
            m[t].pop();
            m[t].push(idx);
        }
        nums.pop_back();
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, priority_queue<int>> m;
};