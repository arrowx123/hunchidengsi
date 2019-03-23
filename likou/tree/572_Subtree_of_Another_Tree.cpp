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
  bool dfs(TreeNode *s, TreeNode *t) {
    if (!s && !t)
      return true;
    else if (!s || !t)
      return false;
    return (s->val == t->val) && dfs(s->left, t->left) &&
           dfs(s->right, t->right);
  }
  bool isSubtree(TreeNode *s, TreeNode *t) {
    return dfs(s, t) || (s && isSubtree(s->left, t)) ||
           (s && isSubtree(s->right, t));
  }
};
