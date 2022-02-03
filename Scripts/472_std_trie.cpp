class Trie {
public:
  struct Node{
    bool eow;
    Node* nb[26];
    Node(){eow = false; for(int i=0;i!=26;i++) nb[i] = NULL;}
  };
  Node *root;

  Trie() {root = new Node(); root->eow = true;}
  
  void insert(string &word) {
    Node *tmp = root;
    
    for(int j = 0, idx ;j < word.size(); j++)
      if(tmp->nb[idx = word[j] - 'a']) tmp = tmp->nb[idx];              //if this node present
      else                                                              //if not
        for(int idx; j != word.size(); j++, tmp = tmp->nb[idx])
          tmp->nb[idx = word[j] - 'a'] = new Node();

    tmp->eow = true;
  }
    
  bool is_concatenated(string &sample, int j){        //check : is the sample concatenation of words from Trie ? 
    Node *tmp = root;
    for(int idx; j < sample.size(); j++){
      if(tmp->nb[idx = sample[j] - 'a']) tmp = tmp->nb[idx];              
      else return false;
      if(tmp->eow && (j + 1 == sample.size() || is_concatenated(sample, j + 1)) ) return true; 
    }
    return false;  
  }
};

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(), [](string &a, string &b) -> bool{return a.size() < b.size();});
    Trie t;
    vector<string> answer;
    
    for(auto &w: words)
      if(t.is_concatenated(w,0)) answer.push_back(w);
      else t.insert(w);
    
    return answer;  
  }
};