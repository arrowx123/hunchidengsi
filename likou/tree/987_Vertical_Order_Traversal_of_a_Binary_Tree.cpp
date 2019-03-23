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
  void dfs(TreeNode *node, map<int, vector<pair<int, int>>> &record, int x,
           int y) {
    if (!node)
      return;

    record[x].push_back({y, node->val});
    dfs(node->left, record, x - 1, y + 1);
    dfs(node->right, record, x + 1, y + 1);
    return;
  }
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, vector<pair<int, int>>> record;
    dfs(root, record, 0, 0);

    vector<vector<int>> ans;

    for (map<int, vector<pair<int, int>>>::iterator it = record.begin();
         it != record.end(); it++) {
      sort((it->second).begin(), (it->second).end());

      vector<int> tmp;

      for (int i = 0; i < (it->second).size(); i++) {
        tmp.push_back((it->second)[i].second);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};
