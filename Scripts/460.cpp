class LFUCache {
private:
    unordered_map<int, int> KV;
    unordered_map<int, list<int>> freqK;
    unordered_map<int, int> kFreq;
    unordered_map<int, list<int>::iterator> kFreqIt;
    int cap;
    int minimumFreq;
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        minimumFreq = INT_MAX;
    }
    
    int get(int key) {
        if (this->cap == 0){
            return -1;
        }
        if (KV.count(key)){
            int freq = kFreq[key];
            kFreq[key] = freq + 1;
            
            freqK[freq].erase(kFreqIt[key]);
            freqK[freq + 1].push_front(key);
            
            kFreqIt[key] = freqK[freq + 1].begin();
            
            if (freqK[freq].empty() && minimumFreq == freq){
                minimumFreq = freq + 1;
            }
            
            return KV[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (KV.count(key)){
            KV[key] = value;
            int freq = kFreq[key];
            kFreq[key] = freq + 1;
            
            freqK[freq].erase(kFreqIt[key]);
            freqK[freq + 1].push_front(key);
            
            kFreqIt[key] = freqK[freq + 1].begin();
            
            if (freqK[freq].empty() && minimumFreq == freq){
                minimumFreq = freq + 1;
            }
            return;
        }

        if (this->cap == 0){
            return;
        }
        if (KV.size() == cap){
            int invK = freqK[minimumFreq].back();
            KV.erase(invK);
            
            freqK[minimumFreq].erase(kFreqIt[invK]);
            
            kFreqIt.erase(invK);
            
            kFreq.erase(invK);
        }

        KV[key] = value;
        freqK[1].push_front(key);
        kFreq[key] = 1;
        kFreqIt[key] = freqK[1].begin();
        minimumFreq = 1;

    }
};