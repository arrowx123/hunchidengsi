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
  TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (!root)
      return nullptr;

    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    if (root->val < L) {
      return root->right;
    } else if (root->val > R) {
      return root->left;
    }
    return root;
  }
};
