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
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> umap;
    stack<TreeNode *> s;

    TreeNode *last = nullptr;
    while (root || s.size()) {
      if (root) {
        s.push(root);
        root = root->left;
      } else {
        TreeNode *cur = s.top();
        if (cur->right && cur->right != last) {
          root = cur->right;
        } else {
          s.pop();
          last = cur;
          if (cur->left)
            cur->val += cur->left->val;
          if (cur->right)
            cur->val += cur->right->val;
          umap[cur->val]++;
        }
      }
    }

    vector<int> ans;
    int max_ = INT_MIN;
    for (auto ele : umap) {
      cout << ele.first << " " << ele.second << endl;
      if (ele.second >= max_) {
        if (ele.second > max_) {
          max_ = ele.second;
          ans.clear();
        }
        ans.push_back(ele.first);
      }
    }
    return ans;
  }
};
