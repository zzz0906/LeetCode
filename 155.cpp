class MinStack {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    TreeNode* root;
    priority_queue<int,vector<int>,greater<int>> singleH;
    stack<int> singleS;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        singleS.push(x);
        singleH.push(x);
    }
    
    void pop() {
        int target = singleS.top();
        for (int i = 0; i < singleH.size(); i++)
            if (singleH[i] == target){
                singleH.erase(singleH.begin() + i);
                break;
            }
        singleS.pop();
        
    }
    
    int top() {
        return singleS.top();
    }
    
    int getMin() {
        return singleH.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */