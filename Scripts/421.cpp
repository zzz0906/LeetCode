#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    int maxLengthValue;
    TreeNode* buildTrie(vector<string> binarys){
        //left 0 right 1
        TreeNode* head = new TreeNode(-1);
        for (auto binary : binarys){
            TreeNode* tmp = head;
            for (auto c : binary){
                if (c == '0'){
                    if (tmp->left){
                        tmp = tmp->left;
                    }else{
                        tmp->left = new TreeNode('0');
                        tmp = tmp->left;
                    }
                }else{
                    if (tmp->right){
                        tmp = tmp->right;
                    }else{
                        tmp->right = new TreeNode('1');
                        tmp = tmp->right;
                    }
                }
            }
        }
        return head;
    }
    int calMaxXor(string binary, TreeNode* head){
        long long ans = 0;
        long long multiplier = 1 << (maxLengthValue - 1);
        TreeNode* tmp = head;
        for (auto c : binary){
            //cout << c << endl;
            if (c == '0'){
                if (tmp->right){
                    ans += multiplier * 1;
                    multiplier /= 2;
                    tmp = tmp->right;
                }else{
                    tmp = tmp->left;
                }
            }else{
                if (tmp->left){
                    ans += multiplier * 1;
                    multiplier /= 2;
                    tmp = tmp->left;
                }else{
                    tmp = tmp->right;
                }
            }
        }
        return ans;
    }
    int max(int a, int b){
        return a >= b ? a : b;
    }
    string transfer(int orig){
        string res = "";
        while (orig > 0){
            // 17 % 2 1; 8 % 2 0; 4 % 2 0; 2 % 2 0; 1 % 2 1; 10001 => 1*2^4 + 1
            res += '0' + orig % 2;
            orig /= 2;
        }
        return res;
    }
    int maxLength(vector<string> nums){
        int res = INT_MIN;
        for (string s: nums){
            res = max(res, s.size());
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<string> binarys;
        for (int num: nums){
            binarys.push_back(transfer(num));
        }
        maxLengthValue = maxLength(binarys);
        for (auto & binary : binarys){
            binary = string(maxLengthValue - binary.size(),'0') + binary;
        }
        TreeNode* head = buildTrie(binarys);
        int res = INT_MIN;
        for (auto binary : binarys){
            res = max(res,calMaxXor(binary,head));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> test{3,10,5,25,2,8};
    cout << s.findMaximumXOR(test)<< endl;
}