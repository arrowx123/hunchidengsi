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
  int dfs(TreeNode *root, int &ans) {
    if (!root)
      return 0;

    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);

    int sum = (root->val) + (l > 0 ? l : 0) + (r > 0 ? r : 0);
    ans = sum > ans ? sum : ans;

    return (root->val) + (max(l, r) > 0 ? max(l, r) : 0);
  }

public:
  int maxPathSum(TreeNode *root) {
    int ans = INT_MIN;
    dfs(root, ans);
    return ans;
  }
};
