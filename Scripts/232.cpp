class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!st.empty()) {
            tmp.push(st.top()); st.pop();
        }
        st.push(x);
        while (!tmp.empty()) {
            st.push(tmp.top()); tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = st.top(); st.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
    
private:
    stack<int> st;
};