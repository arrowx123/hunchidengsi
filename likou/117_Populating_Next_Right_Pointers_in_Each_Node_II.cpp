// level-order traverse
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
private:
  Node *get_next(Node *&node, Node *cur) {
    if (!node)
      return nullptr;

    for (; node; node = node->next) {
      if (node->right && node->right == cur)
        continue;
      if (node->left && node->left != cur)
        return node->left;
      if (node->right && node->right != cur)
        return node->right;
    }
    return nullptr;
  }

public:
  Node *connect(Node *root) {
    Node *p = nullptr;
    Node *cur = root;

    while (cur) {

      Node *cp = cur;
      Node *next = get_next(p, cur);
      while (next) {
        cur->next = next;
        cur = cur->next;
        next = get_next(p, cur);
      }

      for (; cp && (!cp->left && !cp->right); cp = cp->next) {
      }
      p = cp;
      if (cp && cp->left)
        cur = cp->left;
      else if (cp && cp->right)
        cur = cp->right;
      else
        break;
    }
    return root;
  }
};
