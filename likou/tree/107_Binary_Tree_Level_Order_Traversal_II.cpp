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
  void dfs(TreeNode *node, vector<vector<int>> &ans, int level) {
    if (!node)
      return;

    vector<int> tmp;
    if (ans.size() < level) {
      ans.insert(ans.begin(), vector<int>{});
    }
    dfs(node->left, ans, level + 1);
    dfs(node->right, ans, level + 1);
    ans[ans.size() - level].push_back(node->val);
    return;
  }

public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans;
    dfs(root, ans, 1);
    return ans;
  }
};
