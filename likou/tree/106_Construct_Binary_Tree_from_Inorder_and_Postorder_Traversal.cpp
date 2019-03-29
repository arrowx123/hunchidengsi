// recursion
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
  unordered_map<int, int> idx;
  int pos;
  TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int i, int j) {
    if (i == j)
      return nullptr;

    TreeNode *node = new TreeNode(postorder[pos]);
    int p = idx[postorder[pos]];

    pos--;
    node->right = dfs(inorder, postorder, p + 1, j);
    node->left = dfs(inorder, postorder, i, p);
    return node;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); i++)
      idx[inorder[i]] = i;
    pos = postorder.size() - 1;
    return dfs(inorder, postorder, 0, inorder.size());
  }
};
