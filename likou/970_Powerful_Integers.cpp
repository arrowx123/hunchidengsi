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
  vector<int> powerfulIntegers(int x, int y, int bound) {
    vector<int> xs = {1};
    vector<int> ys = {1};
    vector<int> ans;
    unordered_set<int> uset;

    int x_ = 1;
    int y_ = 1;
    while (x_ < bound) {
      x_ *= x;
      xs.push_back(x_);
      if (x == 1)
        break;
    }
    while (y_ < bound) {
      y_ *= y;
      ys.push_back(y_);
      if (y == 1)
        break;
    }

    for (int i = 0; i < (int)xs.size(); i++) {
      for (int j = 0; j < (int)ys.size(); j++) {
        if (xs[i] + ys[j] <= bound)
          uset.insert(xs[i] + ys[j]);
      }
    }

    for (auto ele : uset) {
      ans.push_back(ele);
    }
    return ans;
  }
};
int main() {
  Solution solution;

  int x = 2;
  int y = 3;
  int bound = 10;
  solution.powerfulIntegers(x, y, bound);
  return 0;
}
