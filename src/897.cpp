#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
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
  vector<int> vals;
  void traverse(TreeNode *node) {
    if (node == NULL)
      return;
    traverse(node->left);
    vals.push_back(node->val);
    traverse(node->right);
    return;
  }

public:
  TreeNode *increasingBST(TreeNode *root) {
    traverse(root);
    TreeNode *ans = new TreeNode(0);
    TreeNode *cur = ans;
    for (int i = 0; i < (int)vals.size(); i++) {
      cur->right = new TreeNode(vals[i]);
			cur = cur->right;
    }

    return ans->right;
  }
};
int main() {
  TreeNode *root = new TreeNode(0);
  Solution solution = Solution();
  cout << solution.increasingBST(root);
  return 0;
}
