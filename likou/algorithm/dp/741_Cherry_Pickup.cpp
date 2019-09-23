// 741_Cherry_Pickup
// dp top down
// O(n^3)
typedef pair<int, int> pii;
const int SIZE = 60;
const int MIN = -2139062144;

class Solution {
private:
  int n;
  int map[SIZE][SIZE][SIZE][SIZE];
  vector<vector<int>> grid;

  int getPos(int x, int y) { return x * n + y; }

  int dp(int x1, int y1, int x2, int y2) {
    if (map[x1][y1][x2][y2] != MIN)
      return map[x1][y1][x2][y2];

    if (x1 == n || y1 == n || x2 == n || y2 == n || grid[x1][y1] == -1 ||
        grid[x2][y2] == -1)
      return -(n * n + 10);
    if (x1 == n - 1 && y1 == n - 1)
      return grid[n - 1][n - 1];

    int cur = grid[x1][y1];
    if (x1 != x2)
      cur += grid[x2][y2];
    int max_ = dp(x1 + 1, y1, x2 + 1, y2);
    max_ = max(max_, dp(x1 + 1, y1, x2, y2 + 1));
    max_ = max(max_, dp(x1, y1 + 1, x2 + 1, y2));
    max_ = max(max_, dp(x1, y1 + 1, x2, y2 + 1));

    return map[x1][y1][x2][y2] = cur + max_;
  }

public:
  int cherryPickup(vector<vector<int>> &g) {
    grid = g;
    n = grid.size();
    memset(map, 0x80, sizeof(map));
    return max(dp(0, 0, 0, 0), 0);
  }
};
// dp bottom up
// O(n^3)
class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size();
    if (!n)
      return 0;

    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    dp[0][0] = grid[0][0];

    for (int k = 1; k < 2 * n - 1; k++) {
      vector<vector<int>> tmp(n, vector<int>(n, INT_MIN));
      for (int i = 0; i < n; i++) {
        if (k - i < 0 || k - i >= n || grid[i][k - i] == -1)
          continue;
        for (int j = 0; j < n; j++) {
          if (k - j < 0 || k - j >= n || grid[j][k - j] == -1)
            continue;
          int cur = grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
          int max_ = dp[i][j];
          if (i)
            max_ = max(max_, dp[i - 1][j]);
          if (j)
            max_ = max(max_, dp[i][j - 1]);
          if (i && j)
            max_ = max(max_, dp[i - 1][j - 1]);
          tmp[i][j] = cur + max_;
        }
      }
      dp = tmp;
    }
    return max(dp[n - 1][n - 1], 0);
  }
};
