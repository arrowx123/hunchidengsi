// bfs
class Solution {
private:
  vector<pair<int, int>> offset = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    queue<pair<int, int>> que;
    vector<vector<int>> ans(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!matrix[i][j]) {
          que.push({i, j});
          ans[i][j] = 0;
        }
      }
    }

    while (que.size()) {
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      for (int i = 0; i < offset.size(); i++) {
        int cx = x + offset[i].first;
        int cy = y + offset[i].second;

        if (cx >= 0 && cx < m && cy >= 0 && cy < n && ans[cx][cy] == -1) {
          ans[cx][cy] = ans[x][y] + 1;
          que.push({cx, cy});
        }
      }
    }
    return ans;
  }
};
