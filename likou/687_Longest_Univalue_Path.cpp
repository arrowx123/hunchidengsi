#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
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
  int traverse(TreeNode *node, int value, int &ans) {
    if (node == NULL)
      return 0;

    int l = traverse(node->left, node->val, ans);
    int r = traverse(node->right, node->val, ans);

    ans = max(ans, 1 + l + r);
    if (node->val == value)
      return max(l, r) + 1;
    else
      return 0;
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    int ans = 0;
		if(root == NULL)
			return ans;

    traverse(root, root->val, ans);
    return ans - 1;
  }
};
int main() {
  Solution solution;
  return 0;
}
