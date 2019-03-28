// bottom up
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
  pair<int, int> dfs(TreeNode *node) {
    if (!node)
      return {0, 0};

    pair<int, int> l = dfs(node->left);
    pair<int, int> r = dfs(node->right);

    return {max(l.first, l.second) + max(r.first, r.second),
            node->val + l.first + r.first};
  }

public:
  int rob(TreeNode *root) {
    pair<int, int> ans = dfs(root);
    return max(ans.first, ans.second);
  }
};
