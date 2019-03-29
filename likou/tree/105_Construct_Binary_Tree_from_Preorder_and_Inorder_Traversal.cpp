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
  TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int i1, int j1,
                int i2, int j2) {
    if (i1 == j1)
      return nullptr;

    TreeNode *node = new TreeNode(preorder[i1]);
    int i = idx[preorder[i1]];

    node->left = dfs(preorder, inorder, i1 + 1, i1 + 1 + i - i2, i2, i);
    node->right = dfs(preorder, inorder, i1 + 1 + i - i2, j1, i + 1, j2);
    return node;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++)
      idx[inorder[i]] = i;
    return dfs(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
