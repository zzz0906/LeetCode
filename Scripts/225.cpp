class MyStack {
public:
    /** Initialize your data structure here. */
    deque<int> myqueue;
    MyStack() {
        this->myqueue.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->myqueue.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = this->myqueue.back();
        this->myqueue.pop_back();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return this->myqueue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->myqueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */