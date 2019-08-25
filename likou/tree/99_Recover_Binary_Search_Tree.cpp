// 99_Recover_Binary_Search_Tree
// Time Complexity O(n)
// Space Complexity O(n) due to stack
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  TreeNode *x, *y, *last;
  void traverse(TreeNode *node) {
    if (!node)
      return;
    traverse(node->left);
    if (last && node->val < last->val) {
      y = node;
      if (!x)
        x = last;
    }
    last = node;
    traverse(node->right);
    return;
  }

public:
  void recoverTree(TreeNode *root) {
    if (!root)
      return;
    x = y = last = nullptr;
    traverse(root);
    swap(x->val, y->val);
  }
};
