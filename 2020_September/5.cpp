#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode * current;
    deque<TreeNode*> fathers;
    void BSTIterator(TreeNode* root) {
        current = root;
        if (current != NULL){
            while (current->left != NULL) {
                fathers.push_back(current);
                current = current->left;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int current_answer = current->val;
        // if current is the father
        if (current->right != NULL) {
            current = current->right;
            fathers.push_back(current);
            while (current->left != NULL) {
                current = current->left;
                fathers.push_back(current);
            }
        }
        // father then it can be the right's left | not father then can be its fatehr 's point
        if (!fathers.empty()){
            current = fathers.back();
            fathers.pop_back();
        }else current = NULL;

        return current_answer;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current || !fathers.empty();
    }

    TreeNode * current_2;
    deque<TreeNode*> fathers_2;
    void BSTIterator2(TreeNode* root2) {
        if (root2 == NULL) {current_2 = NULL;return;}
        current_2 = root2;
        if (current_2 != NULL){
            while (current_2->left != NULL) {
                fathers_2.push_back(current_2);
                current_2 = current_2->left;
            }
        }
    }
    
    /** @return the next smallest number */
    int next_2() {
        int current_answer = current_2->val;
        // if current is the father
        if (current_2->right != NULL) {
            current_2 = current_2->right;
            fathers_2.push_back(current_2);
            while (current_2->left != NULL) {
                current_2 = current_2->left;
                fathers_2.push_back(current_2);
            }
        }
        // father then it can be the right's left | not father then can be its fatehr 's point
        if (!fathers_2.empty()){
            current_2 = fathers_2.back();
            fathers_2.pop_back();
        }else current_2 = NULL;
        return current_answer;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext_2() {
        return current_2 || !fathers_2.empty();
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        fathers.clear(); fathers_2.clear();
        BSTIterator(root1);
        BSTIterator2(root2);
        vector<int> ans;
        int flag = 0;
        int mid;
        while ((hasNext() && hasNext_2()) || (hasNext() && flag == 2) || (hasNext_2() && flag == 1)){
            if ((hasNext() && hasNext_2()) || (hasNext() && flag == 2) || (hasNext_2() && flag == 1)){
                if (flag == 0){
                    int n1 = next(); int n2 = next_2();
                    if (n1 > n2) {
                        ans.push_back(n2);
                        mid = n1;
                        flag = 1;
                    }else
                    if (n1 < n2) {
                        ans.push_back(n1);
                        mid = n2;
                        flag = 2;
                    }else
                    if (n1 == n2){
                        ans.push_back(n1);ans.push_back(n2); flag = 0;
                    }
                }
                if (flag == 1){
                    int n2 = next_2();
                    if (mid > n2){
                        ans.push_back(n2);
                        flag = 1;
                    }else
                    if (mid < n2){
                        ans.push_back(mid);
                        mid = n2;
                        flag = 2;
                    }else
                    if (mid == n2){
                        ans.push_back(mid); ans.push_back(n2); flag = 0;
                    }
                }
                if (flag == 2){
                    int n1 = next();
                    if (mid > n1){
                        ans.push_back(n1);
                    }else
                    if (mid < n1){
                        ans.push_back(mid);
                        mid = n1;
                        flag = 1;
                    }else
                    if (mid == n1){
                        ans.push_back(mid); ans.push_back(n1); flag = 0;
                    }
                }
            }
        }
        if (flag == 1 || flag == 2)
            ans.push_back(mid);
        while (hasNext())
            ans.push_back(next());
        while (hasNext_2())
            ans.push_back(next_2());
        cout<<ans.size()<<endl;
        return ans;
    }
};
int main(){
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(10);
    TreeNode* root = new TreeNode(3,left,right);
    Solution s;
    s.getAllElements(root,NULL);
}