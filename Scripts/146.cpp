class LRUCache {
public:
    deque<int> LRUq;
    unordered_map<int,int> LRUm;
    int own_capacity;
    LRUCache(int capacity) {
        own_capacity = capacity;
    }
    
    int get(int key) {
        if (LRUm.count(key)){
            deque<int>::iterator it = find(LRUq.begin(), LRUq.end(), key);
            it = LRUq.erase(it);
            LRUq.push_back(key);
            return LRUm[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (LRUq.size() == own_capacity){
            int out = LRUq[0];
            LRUm[out] = -1;
            LRUq.pop_back();
        }else{
            LRUq.push_back(key);
            LRUm.insert(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */