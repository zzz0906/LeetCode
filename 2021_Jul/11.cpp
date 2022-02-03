class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.insert(num);
    }
    
    double findMedian() {
        const size_t n = data.size();
        double median = 0;

        auto iter = data.cbegin();
        std::advance(iter, n / 2);

        if (n % 2 == 0)
        {
            const auto iter2 = iter--;
            median = double(*iter + *iter2) / 2;    // data[n/2 - 1] AND data[n/2]
        }
        else
        {
            median = *iter;
        }

        return median;
    }
    
    multiset<int> data;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */