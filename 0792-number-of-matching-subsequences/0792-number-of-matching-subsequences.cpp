class Trie {
  struct Node {
    int isLeaf;
    vector<int> next;
    Node(){
      isLeaf = 0;
      next = vector<int>(26, -1);
    }
  };
  vector<Node> root;
public:
  Trie(){
    root.push_back(Node());
  }
  void insert(string s){
    int index = 0;
    for (int i = 0; i < s.size(); i++){
      int pos = s[i] - 'a';
      if (root[index].next[pos] == -1){
        root[index].next[pos] = root.size();
        root.push_back(Node());
      }

      index = root[index].next[pos];
    }
    root[index].isLeaf++;
  }
  int getMaxMatchingHelper(vector<vector<int>>& nxt, int strIndex, int trieIndex){
    int cur = root[trieIndex].isLeaf;
    if (strIndex == nxt.size()) return cur;
    for (int toGo = 0; toGo < 26; toGo++){
      if (root[trieIndex].next[toGo] != -1 && nxt[strIndex][toGo] != -1){
        cur += getMaxMatchingHelper(nxt, nxt[strIndex][toGo] + 1, root[trieIndex].next[toGo]);
      }
    }
    return cur;
  }
  int getMaxMatching(vector<vector<int>>& nxt){
    return getMaxMatchingHelper(nxt, 0, 0);
  }
};
class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> nxt((int)s.size());
    nxt[s.size()-1] = vector<int>(26, -1);
    nxt[s.size()-1][s.back()-'a'] = s.size()-1;
    for (int i = s.size()-2; i >= 0; i--){
      nxt[i] = nxt[i+1];
      nxt[i][s[i]-'a'] = i;
    }

    Trie trie;
    for (int i = 0; i < words.size(); i++)
      trie.insert(words[i]);
    return trie.getMaxMatching(nxt);
  }
};