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
  bool traverse(TreeNode *node, int val) {
    if (node == NULL)
      return true;
    if (node->val != val)
      return false;
    return traverse(node->left, val) && traverse(node->right, val);
  }

public:
  bool isUnivalTree(TreeNode *root) {
    int v = root->val;
    return traverse(root, v);
  }
};
int main() {
  Solution solution;
  return 0;
}
