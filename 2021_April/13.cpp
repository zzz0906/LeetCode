/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--){
            res.push_front(nestedList[i]);
        }
        this->hasNext();
        //res.pop_front();
        //cout<<res.front().getInteger();
    }
    
    int next() {
        int ans = res.front().getInteger();
        res.pop_front();
        return ans;
    }
    
    bool hasNext() {
        if (!res.empty()){
            if (res.front().isInteger()){
                return true;
            }else{
                //while (res.front.getList())
                while (!res.empty() && !res.front().isInteger()){
                    //vector<NestedInteger> tmpl = res.front().getList();
                    NestedInteger t = res.front();
                    res.pop_front();
                    for (int i = t.getList().size() - 1; i >= 0; i--)
                        res.push_front(t.getList()[i]);
                }
                if (res.empty())
                    return false;
                return true;
            }
        }
        return false;
    }
private:
    deque<NestedInteger> res;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */