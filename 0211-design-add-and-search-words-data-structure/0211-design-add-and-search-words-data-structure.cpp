/*
 * we will design a trie, when we search and we are with a dot we can go to every next path
 */
class WordDictionary {
private:
  class Trie{
    public:
      bool isLeaf;
      vector<int> next;
      Trie(){
        isLeaf = 0;
        next = vector<int>(26, -1);
      }
  };
public:
  vector<Trie> root;
  WordDictionary() {
    root.push_back(Trie());
  }

  void addWord(string word) {
    int ptr = 0;
    for (int i = 0; i < word.size(); i++){
      if (root[ptr].next[word[i] - 'a'] == -1){
        root[ptr].next[word[i] - 'a'] = root.size();
        root.push_back(Trie());
      }
      ptr = root[ptr].next[word[i] - 'a'];
    }
    root[ptr].isLeaf = 1;
  }
  bool dfs(int ptr, string& pat, int index){
    if (index == pat.size()) return root[ptr].isLeaf;
    if (pat[index] == '.'){
      for (int i = 0; i < 26; i++){
        if (root[ptr].next[i] != -1 && dfs(root[ptr].next[i], pat, index + 1))
          return 1;
      }
    }else {
      if (root[ptr].next[pat[index] - 'a'] != -1)
        return dfs(root[ptr].next[pat[index] - 'a'], pat, index + 1);
    }
    return 0;
  }
  bool search(string word) {
    return dfs(0, word, 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */