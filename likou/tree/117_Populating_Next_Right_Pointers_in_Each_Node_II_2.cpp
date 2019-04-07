// level-order traverse
// extra space
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return nullptr;

    deque<Node *> deq;
    deq.push_back(root);

    while (deq.size()) {
      int size = deq.size();
      for (int i = 0; i < size; i++) {
        Node *node = deq.front();
        deq.pop_front();

        if (i != size - 1)
          node->next = deq.front();
        if (node->left)
          deq.push_back(node->left);
        if (node->right)
          deq.push_back(node->right);
      }
    }
    return root;
  }
};
