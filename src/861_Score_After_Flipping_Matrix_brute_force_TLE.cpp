#include <algorithm>
#include <iostream>
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
class Solution {
public:
  int matrixScore(vector<vector<int>> &A) {
    int m = A.size();
    int n = A[0].size();
    int ans = 0;

    for (int i = 0; i < (1 << m); i++) {
      if (i > 0) {
        int change = i ^ (i - 1);
        for (int j = 0; j < m; j++) {
          if (((change >> j) & 1) == 1) {
            for (int k = 0; k < n; k++) {
              A[j][k] = (A[j][k] == 1) ? 0 : 1;
            }
          }
        }
      }
      int tmp = 0;
      for (int k = 0; k < n; k++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
          sum += A[j][k];
        }
        tmp += max(m - sum, sum) * (1 << (n - 1 - k));
      }
      ans = max(ans, tmp);
    }

    return ans;
  }
};
int main() {
  vector<vector<int>> A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  Solution solution;
  cout << solution.matrixScore(A);
  return 0;
}
