// 426_Convert_Binary_Search_Tree_to_Sorted_Doubly_Linked_List
// tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
  Node *first = nullptr;
  Node *last = nullptr;

  void traverse(Node *node) {
    if (!node)
      return;
    traverse(node->left);
    if (last) {
      last->right = node;
      node->left = last;
    } else
      first = node;
    last = node;
    traverse(node->right);
    return;
  }

public:
  Node *treeToDoublyList(Node *root) {
    if (!root)
      return root;

    traverse(root);
    first->left = last;
    last->right = first;
    return first;
  }
};
