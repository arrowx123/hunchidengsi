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
public:
  TreeNode *traverse(TreeNode *node, int val) {
    if (!node)
      return NULL;
    if (node->val == val)
      return node;
    else {
      TreeNode *l = traverse(node->left, val);
      TreeNode *r = traverse(node->right, val);
      if (!l && !r)
        return NULL;
      else if (l)
        return l;
      else
        return r;
    }
  }
  TreeNode *searchBST(TreeNode *root, int val) { return traverse(root, val); }
};
int main() {
  Solution solution;
  return 0;
}
