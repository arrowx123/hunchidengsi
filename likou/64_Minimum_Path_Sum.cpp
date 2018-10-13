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
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> sum(m, vector<int>(n));
    sum[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
      sum[0][i] = sum[0][i - 1] + grid[0][i];

    for (int i = 1; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (!j)
          sum[i][j] = sum[i - 1][j] + grid[i][j];
        else {
          sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]);
          sum[i][j] += grid[i][j];
        }
      }
    return sum[m - 1][n - 1];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution solution;
  cout << solution.minPathSum(grid);
  return 0;
}
