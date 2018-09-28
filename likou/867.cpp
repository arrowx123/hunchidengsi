#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
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
  vector<vector<int>> transpose(vector<vector<int>> &A) {

    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans[j][i] = A[i][j];
      }
    }
    return ans;
  }
};
int main() {
  vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution solution = Solution();
  solution.transpose(A);
  return 0;
}
