class Trie {
public:
    /** Initialize your data structure here. */
    struct ListNode {
        char val;
        vector<ListNode*> next;
        vector<bool> end;
        ListNode() : val('A'){}
        ListNode(char x) : val(x) {}
    };
    ListNode* head;
    Trie() {
        ListNode* tmp = new ListNode();
        head = tmp;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        ListNode* tmp = this->head;
        int k = 0;
        for (char c : word) {
            bool flag = false;
            int index = -1;
            for (int i = 0; i < tmp->next.size(); i++){
                if (tmp->next[i]->val == c){
                    flag = true;
                    index = i;
                    break;
                }
            }
            if (flag == false){
                if (k != word.size()-1)
                    tmp->end.push_back(false);
                else
                    tmp->end.push_back(true); 
                tmp->next.push_back(new ListNode(c));
                tmp = tmp->next[tmp->next.size()-1];
            }
            if (flag){
                if (k == word.size()-1)
                    tmp->end[index] = true;
                tmp = tmp->next[index];
            }   
            k++;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        ListNode* tmp = this->head;
        int k = 0;
        for (char c : word) {
            bool flag = false;
            for (int i = 0; i < tmp->next.size(); i++){
                if (tmp->next[i]->val == c){
                    flag = true;
                    if (k == word.size()-1 && tmp->end[i] == false)
                        flag = false;
                    tmp = tmp->next[i];
                    break;
                }
            }
            if (flag == false) return flag;
            k++;
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        ListNode* tmp = this->head;
        for (char c : prefix) {
            bool flag = false;
            for (int i = 0; i < tmp->next.size(); i++){
                if (tmp->next[i]->val == c){
                    flag = true;
                    tmp = tmp->next[i];
                    break;
                }
            }
            if (flag == false) return flag;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */