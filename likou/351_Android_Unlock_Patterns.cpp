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
private:
  vector<bool> used;
  bool is_valid(int last, int curr) {
    if (used[curr])
      return false;
    if (last == -1)
      return true;
    if ((last + curr) % 2)
      return true;
    int mid = (last + curr) / 2;
    if (mid == 5)
      return used[mid];
    if ((last % 3 != curr % 3) && ((last - 1) / 3 != (curr - 1) / 3)) {
      return true;
    }
    return used[mid];
  }
  int get_cnt(int last, int len) {
    if (!len)
      return 1;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
      if (is_valid(last, i)) {
        used[i] = true;
        ans += get_cnt(i, len - 1);
        used[i] = false;
      }
    }
    return ans;
  }

public:
  int numberOfPatterns(int m, int n) {
    used.resize(10, false);
    int ans = 0;
    for (int i = m; i <= n; i++) {
      ans += get_cnt(-1, i);
      for (int j = 0; j < 10; j++)
        used[j] = false;
    }

    return ans;
  }
};
int main() {
  int m = 3;
  int n = 3;
  Solution solution;
  cout << solution.numberOfPatterns(m, n);
  return 0;
}
