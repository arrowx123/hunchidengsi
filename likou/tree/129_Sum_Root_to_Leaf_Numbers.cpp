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
  int dfs(TreeNode *node, int sum) {
    if (!node)
      return 0;

    sum = 10 * sum + node->val;
    int cv = 0;
    cv += dfs(node->left, sum);
    cv += dfs(node->right, sum);

    if (!cv)
      cv = sum;

    return cv;
  }

public:
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};
