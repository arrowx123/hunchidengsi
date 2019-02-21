#include <algorithm>
#include <iostream>
#include <math.h>
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};
class Solution {
private:
  void traverse(TreeNode *node, vector<int> &v) {
    if (node == NULL)
      return;
    traverse(node->left, v);
    v.push_back(node->val);
    traverse(node->right, v);
    return;
  }

public:
  int rangeSumBST(TreeNode *root, int L, int R) {
    vector<int> v;
    traverse(root, v);
    int ans = 0;

    for (int i = 0; i < (int)v.size(); i++) {
      if (v[i] >= L && v[i] <= R)
        ans += v[i];
    }
    return ans;
  }
};
int main() {
  Solution solution;
  return 0;
}
