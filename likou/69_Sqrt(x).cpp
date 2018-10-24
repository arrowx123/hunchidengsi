#include <algorithm>
#include <iostream>
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
class Solution {
public:
  int mySqrt(int x) {
    int l = 0;
    int r = x;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      long square = (long)mid * mid;
      if (square >= x) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if (r * r == x)
      return r;
    return l;
  }
};
int main() {
  int x = 8;
  Solution solution;
  cout << solution.mySqrt(x);
  return 0;
}
