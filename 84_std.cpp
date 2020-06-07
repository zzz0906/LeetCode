class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); i++) {
            //cout<<i<<endl;
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i);
            } else {
                cout<<st.top()<<endl;
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }     
        }
        return res;
    }
};