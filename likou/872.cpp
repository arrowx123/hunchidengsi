#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void get_leaf(TreeNode *root, vector<int> &lv) {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL) {
      lv.push_back(root->val);
    } else {
      get_leaf(root->left, lv);
      get_leaf(root->right, lv);
    }
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> ll;
    vector<int> lr;

    get_leaf(root1, ll);
    get_leaf(root2, lr);
    if (ll.size() != lr.size())
      return false;
    for (int i = 0; i < (int)ll.size(); i++) {
      if (ll[i] != lr[i])
        return false;
    }
    return true;
  }
};

int main() {
  Solution solution = Solution();
  TreeNode *root1 = new TreeNode(1);
  TreeNode *root2 = new TreeNode(1);

  cout << solution.leafSimilar(root1, root2);
  return 0;
}
