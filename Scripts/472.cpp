class Solution {
public:
    struct TreeNode{
        int end;
        TreeNode* child[26];
        TreeNode():end(0){
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    }
    int res = 0;
    void dfs(TreeNode* root){
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TreeNode* root = new TreeNode();
        for (auto word : words){
            TreeNode* cur = root;
            for (int i = 0; i < word.size(); i++){
                if (cur->child[word[i] - 'a'] == nullptr){
                    cur->child[word[i] - 'a'] = new TreeNode();
                    cur = cur->child[word[i] - 'a'];
                }else{
                    cur = cur->child[word[i] - 'a'];
                }
                if (i == word.size() - 1){
                    cur->end += 1;
                }
            }
        }
        //dfs the trie
    }
};