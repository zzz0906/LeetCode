#include <bits/stdc++.h>
using namespace std;
class Trie {
    public:
        struct Node{
            bool eow;
            Node* nb[26];
            Node():eow(false){
                for(int i = 0; i != 26; i++) 
                    nb[i] = nullptr;
            }
        };
        Node *root;

        Trie() {
            root = new Node(); 
            root->eow = true;
        }
        
        void insert(string &word) {
            Node *tmp = root;
            for(int j = 0, idx ;j < word.size(); j++)
                if(tmp->nb[idx = word[j] - 'a'])
                    //if this node present
                    tmp = tmp->nb[idx];         
                else{                                                     
                    //if not
                    for(int idx; j != word.size(); j++, tmp = tmp->nb[idx])
                        tmp->nb[idx = word[j] - 'a'] = new Node();
                }
            tmp->eow = true;
        }
};