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
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> d(m + 1, vector<bool>(n + 1));
    d[0][0] = true;

    for (int i = 2; i <= n; i++)
      d[0][i] = (d[0][i - 2] && p[i - 1] == '*');

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] != '*')
          d[i][j] =
              (d[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
        else
          d[i][j] =
              (d[i][j - 2] ||
               ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && d[i - 1][j]));
      }
    }
    return d[m][n];
  }
};
int main() {
  string s = "mississippi";
  string p = "mis*is*p*.";
  Solution solution;
  cout << solution.isMatch(s, p);
  return 0;
}
