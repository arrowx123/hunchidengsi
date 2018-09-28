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

    for (int i = 0; i < n; i++) {
      int tmp = 0;
      for (int j = 0; j < m; j++) {
        tmp += A[j][i] ^ A[j][0];
      }
      ans += max(tmp, m - tmp) * (1 << (n - 1 - i));
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
