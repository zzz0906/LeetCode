class Solution {
public:
    vector<int> v;
    int N, m;
    
    Solution(int _m, int n) {
        m = _m; N = m*n;
        
        v.assign(N, 0);
        
        for(int i = 0; i < N; i++) 
            v[i] = i;
    }
    
    vector<int> flip() {
        int index = rand() % N;
        
        swap(v[index], v[--N]);
        
        return {v[N] % m, v[N] / m};
    }
    
    void reset() {
        N = v.size();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */