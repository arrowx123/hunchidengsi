// 4 liner

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
public:
  TreeNode *pruneTree(TreeNode *root) {
    if (!root)
      return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return root->val == 1 ? root
                          : (!root->left && !root->right) ? nullptr : root;
  }
};
