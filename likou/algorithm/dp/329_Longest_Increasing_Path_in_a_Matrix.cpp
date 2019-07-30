// 329_Longest_Increasing_Path_in_a_Matrix
// dp
class Solution {
private:
  int m, n;
  vector<vector<int>> matrix;
  vector<vector<int>> len;
  int diff[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

  int dfs(int x, int y) {
    if (len[x][y])
      return len[x][y];

    int max_ = 0;
    for (int i = 0; i < 4; i++) {
      int cx = x + diff[i][0];
      int cy = y + diff[i][1];
      if (cx >= 0 && cx < m && cy >= 0 && cy < n &&
          matrix[cx][cy] > matrix[x][y]) {
        max_ = max(max_, dfs(cx, cy));
      }
    }
    return len[x][y] = max_ + 1;
  }

public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size();
    if (!m)
      return 0;
    n = matrix[0].size();
    len.resize(m, vector<int>(n));
    this->matrix = matrix;

    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, dfs(i, j));
      }
    }
    return ans;
  }
};
