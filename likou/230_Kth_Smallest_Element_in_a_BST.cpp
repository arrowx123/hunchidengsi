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
  void traverse(TreeNode *node, int &cnt, int &ans, const int &k) {
    if (node == NULL || cnt >= k)
      return;
    traverse(node->left, cnt, ans, k);
    cnt++;
    if (cnt == k)
      ans = node->val;
    traverse(node->right, cnt, ans, k);

    return;
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    int ans = 0;
    int cnt = 0;
    traverse(root, cnt, ans, k);
    return ans;
  }
};
int main() {
  Solution solution;
  return 0;
}
