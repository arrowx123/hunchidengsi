// dfs
class Solution {
private:
  vector<vector<int>> move = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  void dfs(vector<vector<bool>> &v, vector<vector<int>> &A, int i, int j, int m,
           int n) {
    v[i][j] = true;
    for (auto ele : move) {
      int cx = i + ele[0];
      int cy = j + ele[1];

      if (cx >= 0 && cx < m && cy >= 0 && cy < n && A[cx][cy] && !v[cx][cy]) {
        dfs(v, A, cx, cy, m, n);
      }
    }
  }

public:
  int numEnclaves(vector<vector<int>> &A) {
    int ans = 0;
    int m = A.size();
    if (!m)
      return ans;
    int n = A[0].size();
    vector<vector<bool>> v(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!v[i][j] && A[i][j]) {
          if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
            dfs(v, A, i, j, m, n);
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (A[i][j] && !v[i][j]) {
          ans++;
        }
      }
    }
    return ans;
  }
};
