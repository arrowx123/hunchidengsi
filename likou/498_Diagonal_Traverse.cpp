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
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int m = matrix.size();
    if (!m)
      return ans;
    int n = matrix[0].size();

    bool order = false;
    for (int k = 0; k < m + n - 1; k++) {
      for (int i = 0; i <= k; i++) {
        int x = order ? i : k - i;
        int y = order ? k - i : i;

        if (x >= m || y >= n)
          continue;
        ans.push_back(matrix[x][y]);
      }
      order = !order;
    }
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";
    return ans;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution solution;
  solution.findDiagonalOrder(matrix);
  return 0;
}
