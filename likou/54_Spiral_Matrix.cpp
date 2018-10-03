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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int m = matrix.size();
		if(!m)
			return ans;
    int n = matrix[0].size();

    int r0 = 0;
    int r1 = m - 1;
    int c0 = 0;
    int c1 = n - 1;

    while (r0 < r1 && c0 < c1) {
      for (int i = c0; i < c1; i++)
        ans.push_back(matrix[r0][i]);
      for (int i = r0; i < r1; i++)
        ans.push_back(matrix[i][c1]);
      for (int i = c1; i > c0; i--)
        ans.push_back(matrix[r1][i]);
      for (int i = r1; i > r0; i--)
        ans.push_back(matrix[i][c0]);
      r0++;
      r1--;
      c0++;
      c1--;
    }

    if (r0 == r1)
      for (int i = c0; i <= c1; i++)
        ans.push_back(matrix[r0][i]);
    else if (c1 == c0)
      for (int i = r0; i <= r1; i++)
        ans.push_back(matrix[i][c0]);

    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";
    return ans;
  }
};
int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution solution;
  solution.spiralOrder(matrix);
  return 0;
}
