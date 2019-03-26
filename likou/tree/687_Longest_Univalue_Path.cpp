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
  int dfs(TreeNode *node, int val, int &ans) {
    if (!node)
      return 0;

    int l = dfs(node->left, node->val, ans);
    int r = dfs(node->right, node->val, ans);

    ans = max(ans, 1 + r + l);

    if (node->val == val) {
      return max(l, r) + 1;
    }
    return 0;
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    int ans = 1;
    dfs(root, 0, ans);
    return ans - 1;
  }
};
