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
  static bool cmp(vector<int> p1, vector<int> p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
  }

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    sort(points.begin(), points.end(), cmp);
    vector<vector<int>> ans;

    for (int i = 0; i < K; i++)
      ans.push_back(points[i]);
    return ans;
  }
};
int main() {
  Solution solution;

  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  int K = 2;
  solution.kClosest(points, K);
  return 0;
}
