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
  void recursion(vector<vector<int>> &points, vector<vector<int>> &ps, int pos,
                 double &ans) {

    if (ps.size() == 3) {
      double x1 = ps[0][0];
      double y1 = ps[0][1];
      double x2 = ps[1][0];
      double y2 = ps[1][1];
      double x3 = ps[2][0];
      double y3 = ps[2][1];
      double area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);

      ans = max(ans, area);
      return;
    }

    int size = points.size();
    for (int i = pos; i < size; i++) {
      ps.push_back(points[i]);
      recursion(points, ps, i + 1, ans);
      ps.pop_back();
    }
    return;
  }

public:
  double largestTriangleArea(vector<vector<int>> &points) {
    double ans = 0;
    vector<vector<int>> pos;
    recursion(points, pos, 0, ans);
    return ans;
  }
};

int main() {
  Solution solution;

  vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
  cout << solution.largestTriangleArea(points);
  return 0;
}
