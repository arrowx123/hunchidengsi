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
    if (root) {
      Node *h = new Node(0);
      h->left = root;
      Node *node, *p;

      vector<Node *> v{h};
      while (v.size()) {
        node = v.back()->left;
        v.pop_back();

        for (; node; node = node->right) {
          for (p = node->next; p && !p->left && !p->right; p = p->next) {
          }
          if (p) {
            p = p->left ? p->left : p->right;
          }
          if (node->right) {
            node->right->next = p;
            p = node->right;
          }
          if (node->left) {
            node->left->next = p;
          }

          v.push_back(node);
        }
      }
    }
    return root;
  }
};
