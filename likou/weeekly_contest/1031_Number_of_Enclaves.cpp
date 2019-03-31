// bfs
class Solution {
private:
  vector<vector<int>> move = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

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
            v[i][j] = true;
            queue<pair<int, int>> que;
            que.push({i, j});
            while (que.size()) {
              pair<int, int> cur = que.front();
              que.pop();
              for (auto ele : move) {
                int cx = cur.first + ele[0];
                int cy = cur.second + ele[1];

                if (cx >= 0 && cx < m && cy >= 0 && cy < n && A[cx][cy] &&
                    !v[cx][cy]) {
                  v[cx][cy] = true;
                  que.push({cx, cy});
                }
              }
            }
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
