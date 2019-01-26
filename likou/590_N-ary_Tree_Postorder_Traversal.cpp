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
  void traverse(Node *node, vector<int> &ans) {
    if (!node)
      return;

    int size = node->children.size();
    for (int i = 0; i < size; i++) {
      traverse(node->children[i], ans);
    }
    ans.push_back(node->val);
  }
  vector<int> postorder(Node *root) {
    vector<int> ans;
    traverse(root, ans);
    return ans;
  }
};
int main() {
  Solution solution;
  return 0;
}
