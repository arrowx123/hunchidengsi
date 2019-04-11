// dp
#define MAX 10000 + 10
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, MAX));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!matrix[i][j]) {
          ans[i][j] = 0;
          continue;
        }
        if (i)
          ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
        if (i < m - 1)
          ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
        if (j)
          ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
        if (j < n - 1)
          ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i)
          ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
        if (i < m - 1)
          ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
        if (j)
          ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
        if (j < n - 1)
          ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
      }
    }

    return ans;
  }
};
