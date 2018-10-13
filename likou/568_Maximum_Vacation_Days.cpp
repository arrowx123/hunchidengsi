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
  int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
    int m = flights.size();
    int n = days[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!i) {
          if (!j) {
            ans[j][i] = days[j][i];
          } else {
            if (flights[0][j])
              ans[j][i] = days[j][i];
            else
              ans[j][i] = -1;
          }
        } else {
          int tmp = INT_MIN;
          for (int k = 0; k < m; k++) {
            if (flights[k][j] && ans[k][i - 1] != -1)
              tmp = max(tmp, ans[k][i - 1]);
          }
          if (ans[j][i - 1] != -1)
            tmp = max(tmp, ans[j][i - 1]);
          if (tmp == INT_MIN)
            ans[j][i] = -1;
          else
            ans[j][i] = days[j][i] + tmp;
        }
      }
    }

    int max_ = 0;
    for (int i = 0; i < m; i++) {
      max_ = max(max_, ans[i][n - 1]);
    }

    return max_;
  }
};
int main() {
  vector<vector<int>> flights = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  vector<vector<int>> days = {{1, 1, 1}, {7, 7, 7}, {7, 7, 7}};
  Solution solution;
  cout << solution.maxVacationDays(flights, days);
  return 0;
}
