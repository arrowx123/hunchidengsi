// 208_Implement_Trie
// trie
const int alphaSize = 26;
struct Node {
  bool end;
  Node *children[alphaSize];
  Node() {
    end = false;
    for (int i = 0; i < alphaSize; i++)
      children[i] = nullptr;
  }
};

class Trie {
private:
  Node *root;

public:
  /** Initialize your data structure here. */
  Trie() { root = new Node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      int ch = word[i] - 'a';
      if (!node->children[ch]) {
        node->children[ch] = new Node();
      }
      node = node->children[ch];
    }
    node->end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      int ch = word[i] - 'a';
      if (!node->children[ch])
        return false;
      node = node->children[ch];
    }
    return node->end;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Node *node = root;
    for (int i = 0; i < prefix.size(); i++) {
      int ch = prefix[i] - 'a';
      if (!node->children[ch])
        return false;
      node = node->children[ch];
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
