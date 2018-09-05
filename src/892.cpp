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
private:
  vector<int> x = {-1, 1, 0, 0};
  vector<int> y = {0, 0, 1, -1};

public:
  int surfaceArea(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < (int)x.size(); k++) {

          int nx = i + x[k];
          int ny = j + y[k];
          int nh = 0;
          if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            nh = grid[nx][ny];
          ans += max(grid[i][j] - nh, 0);
        }
        ans += (grid[i][j] > 0) ? 2 : 0;
      }
    }
    return ans;
  }
};
int main() {
  vector<vector<int>> grid = {{1, 2}, {3, 4}};
  Solution solution = Solution();
  cout << solution.surfaceArea(grid);
  return 0;
}
