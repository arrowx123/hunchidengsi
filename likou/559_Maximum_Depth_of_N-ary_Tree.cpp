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
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
class Solution {
public:
  int traverse(Node *node) {
    if (node == NULL)
      return 0;
    else {
      int size = node->children.size();
      int max_len = 0;
      for (int i = 0; i < size; i++) {
        int current_len = traverse(node->children[i]);
        if (max_len < current_len)
          max_len = current_len;
      }
      return 1 + max_len;
    }
  }
  int maxDepth(Node *root) { return traverse(root); }
};
int main() {
  Solution solution;
  return 0;
}
