#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Robot {
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};
class Solution {
private:
  vector<TreeNode *> v;
  void dfs(TreeNode *node) {
    if (!node)
      return;
    dfs(node->left);
    v.push_back(node);
    dfs(node->right);
    return;
  }

public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    dfs(root);
    int i = 0;
    for (; i < (int)v.size(); i++) {
      if (v[i] == p)
        break;
    }
    if (i == (int)v.size() - 1)
      return NULL;
    return v[i + 1];
  }
};
int main() {
  Solution solution;
  return 0;
}
