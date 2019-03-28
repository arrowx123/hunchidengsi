// recursion
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
  void dfs(Node *node, Node *next) {
    if (!node)
      return;

    node->next = next;
    dfs(node->left, node->right);
    dfs(node->right, node->next ? node->next->left : nullptr);
    return;
  }

public:
  Node *connect(Node *root) {
    if (!root)
      return root;

    dfs(root, nullptr);
    return root;
  }
};
