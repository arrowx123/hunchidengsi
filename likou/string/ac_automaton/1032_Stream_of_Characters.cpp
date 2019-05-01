// 1032_Stream_of_Characters
// ac_automaton original
const int SIGMA = 26;
struct Node {
  bool isEnd;
  Node *fail;
  Node *children[SIGMA];
  Node() {
    for (int i = 0; i < SIGMA; i++)
      children[i] = nullptr;
    fail = nullptr;
    isEnd = false;
  }
};

class StreamChecker {
private:
  Node *root;
  Node *last;

  Node *newNode(Node *root) {
    Node *node = new Node();
    node->fail = root;
    return node;
  }
  void insert(Node *root, string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      int ch = word[i] - 'a';
      if (!node->children[ch])
        node->children[ch] = newNode(root);
      node = node->children[ch];
    }
    node->isEnd = true;
    ;
  }
  void buildFail(Node *root) {
    queue<Node *> que;
    que.push(root);

    while (que.size()) {
      Node *node = que.front();
      que.pop();

      for (int i = 0; i < SIGMA; i++) {
        if (!node->children[i])
          continue;
        que.push(node->children[i]);
        if (node == root)
          continue;

        Node *p = node->fail;
        while (!p->children[i] && p != root)
          p = p->fail;
        node->children[i]->fail = p->children[i] ? p->children[i] : root;
      }
    }
  }

public:
  StreamChecker(vector<string> &words) {
    root = new Node();
    for (auto word : words)
      insert(root, word);
    buildFail(root);
    last = root;
  }

  bool query(char letter) {
    int ch = letter - 'a';
    while (!last->children[ch] && last != root)
      last = last->fail;
    last = last->children[ch] ? last->children[ch] : root;

    Node *tmp = last;
    while (tmp != root) {
      if (tmp->isEnd)
        return true;
      tmp = tmp->fail;
    }
    return false;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
