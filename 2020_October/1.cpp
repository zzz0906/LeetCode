class RecentCounter {
public:
    deque<int> thousands_3;
    RecentCounter() {
       
    }
    
    int ping(int t) {
        int ans = 0;
        thousands_3.push_back(t);
        while (thousands_3.front() < t-3000) {
            if (thousands_3.front() < t-3000) thousands_3.pop_front();
        }
        return thousands_3.size();
    }
    
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */