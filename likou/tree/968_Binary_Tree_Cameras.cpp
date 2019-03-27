// greedy
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
  unordered_set<TreeNode *> uset;
  void dfs(TreeNode *node, TreeNode *p, int &ans) {
    if (!node)
      return;

    dfs(node->left, node, ans);
    dfs(node->right, node, ans);

    if (!p && !uset.count(node) || !uset.count(node->left) ||
        !uset.count(node->right)) {
      ans++;
      uset.insert(node);
      uset.insert(p);
      uset.insert(node->left);
      uset.insert(node->right);
    }
    return;
  }

public:
  int minCameraCover(TreeNode *root) {
    int ans = 0;
    uset.insert(nullptr);
    dfs(root, nullptr, ans);
    return ans;
  }
};
