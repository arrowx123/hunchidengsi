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
  void dfs(TreeNode *node, unordered_map<int, int> &umap, int sum, int s,
           int &ans) {
    if (!node)
      return;

    s += node->val;
    ans += umap[s - sum];
    umap[s]++;
    dfs(node->left, umap, sum, s, ans);
    dfs(node->right, umap, sum, s, ans);
    umap[s]--;
  }

public:
  int pathSum(TreeNode *root, int sum) {
    unordered_map<int, int> umap;
    umap[0] = 1;
    int ans = 0;
    dfs(root, umap, sum, 0, ans);
    return ans;
  }
};
