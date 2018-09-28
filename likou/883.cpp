#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++) {
      int _max = 0;
      for (int j = 0; j < n; j++) {
        if (grid[i][j])
          ans++;
        _max = max(_max, grid[i][j]);
      }
      ans += _max;
    }

    for (int i = 0; i < n; i++) {
      int _max = 0;
      for (int j = 0; j < m; j++) {
        _max = max(_max, grid[j][i]);
      }
      ans += _max;
    }

    return ans;
  }
};
int main() {
  vector<vector<int>> grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  Solution solution = Solution();
  cout << solution.projectionArea(grid);

  return 0;
}
