// top down
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
  unordered_map<TreeNode *, int> umap;
  int dfs(TreeNode *node, bool used) {
    if (!node)
      return 0;
    if (umap.count(node) && !used)
      return umap[node];

    int ans = dfs(node->left, false) + dfs(node->right, false);
    if (!used) {
      ans =
          max(ans, node->val + dfs(node->left, true) + dfs(node->right, true));
      umap[node] = ans;
    }

    return ans;
  }

public:
  int rob(TreeNode *root) { return dfs(root, false); }
};
