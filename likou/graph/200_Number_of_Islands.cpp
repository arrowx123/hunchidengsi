// 200_Number_of_Islands
// O(mn)
// no bfs, dfs, ufs
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    if (!m)
      return 0;
    int n = grid[0].size();

    vector<int> root;
    vector<vector<int>> v(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '0')
          continue;
        if (!j || grid[i][j - 1] == '0')
          root.push_back(root.size());
        v[i][j] = root.back();
        if (i && grid[i - 1][j] == '1') {
          int min_ = min(root[root[root.back()]], root[root[v[i - 1][j]]]);
          root[root[root.back()]] = min_;
          root[root[v[i - 1][j]]] = min_;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < root.size(); i++) {
      ans += root[i] == i;
    }
    return ans;
  }
};
