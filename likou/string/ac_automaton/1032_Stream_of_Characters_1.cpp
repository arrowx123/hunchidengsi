// 1032_Stream_of_Characters
// ac_automaton modified
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
    root->fail = root;
    for (int i = 0; i < word.size(); i++) {
      int ch = word[i] - 'a';
      if (!node->children[ch])
        node->children[ch] = newNode(root);
      node = node->children[ch];
    }
    node->isEnd = true;
  }
  void buildFail(Node *root) {
    queue<Node *> que;
    que.push(root);

    while (que.size()) {
      Node *node = que.front();
      que.pop();

      for (int i = 0; i < SIGMA; i++) {
        if (!node->children[i]) {
          node->children[i] =
              node->fail->children[i] ? node->fail->children[i] : root;
        } else {
          que.push(node->children[i]);
          if (node == root)
            continue;
          node->children[i]->fail = node->fail->children[i];
        }
      }
      node->isEnd |= node->fail->isEnd;
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
    last = last->children[ch];
    return last->isEnd;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
