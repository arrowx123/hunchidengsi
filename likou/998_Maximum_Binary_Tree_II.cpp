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
  TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    TreeNode *node = new TreeNode(val);

    if (!root) {
      return node;
    }

    if (root->val < val) {
      node->left = root;
      return node;
    }
    TreeNode *cu = root;
    TreeNode *p = NULL;
    while (true) {
      if (cu->val > val) {
        if (!cu->right) {
          cu->right = node;
          break;
        } else {
          p = cu;
          cu = cu->right;
        }
      } else {
        p->right = node;
        node->left = cu;
        break;
      }
    }
    return root;
  }
};
int main() {
  Solution solution;

  return 0;
}
