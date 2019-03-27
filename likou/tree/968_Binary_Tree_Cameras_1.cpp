// dp
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
  vector<int> dfs(TreeNode *node) {
    if (!node)
      return {0, 0, 5};

    vector<int> l = dfs(node->left);
    vector<int> r = dfs(node->right);

    return {l[1] + r[1], min(l[2] + min(r[1], r[2]), r[2] + min(l[1], l[2])),
            1 + min(l[0], min(l[1], l[2])) + min(r[0], min(r[1], r[2]))};
  }

public:
  int minCameraCover(TreeNode *root) {
    vector<int> v = dfs(root);
    return min(v[1], v[2]);
  }
};
