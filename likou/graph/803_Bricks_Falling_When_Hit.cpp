// 803_Bricks_Falling_When_Hit
// ufs
class Solution {
private:
  vector<int> p;
  vector<int> cnt;
  vector<vector<int>> diff = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

  int findP(int e) {
    if (p[e] == e)
      return e;
    return p[e] = findP(p[e]);
  }

  void connect(int idx1, int idx2) {
    if (findP(idx1) == findP(idx2))
      return;
    cnt[findP(idx2)] += cnt[findP(idx1)];
    p[findP(idx1)] = p[findP(idx2)];
    return;
  }

public:
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> A = grid;

    p.resize(m * n + 1);
    cnt.resize(m * n + 1);
    for (int i = 0; i < p.size(); i++)
      p[i] = i;
    fill(cnt.begin(), cnt.end(), 1);

    for (int i = 0; i < hits.size(); i++) {
      int x = hits[i][0];
      int y = hits[i][1];
      A[x][y] = 0;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!A[i][j])
          continue;
        int idx = i * n + j;
        if (!i)
          connect(idx, m * n);
        if (i && A[i - 1][j])
          connect(idx, (i - 1) * n + j);
        if (j && A[i][j - 1])
          connect(idx, i * n + j - 1);
      }
    }

    vector<int> ans;
    for (int i = hits.size() - 1; i >= 0; i--) {
      int x = hits[i][0];
      int y = hits[i][1];

      if (!grid[x][y]) {
        ans.push_back(0);
        continue;
      }

      int tmp = cnt[findP(m * n)];
      for (int j = 0; j < diff.size(); j++) {
        int nx = x + diff[j][0];
        int ny = y + diff[j][1];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && A[nx][ny]) {
          connect(x * n + y, nx * n + ny);
        }
      }
      A[x][y] = 1;
      if (!x)
        connect(x * n + y, m * n);
      ans.push_back(max(0, cnt[findP(m * n)] - tmp - 1));
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
