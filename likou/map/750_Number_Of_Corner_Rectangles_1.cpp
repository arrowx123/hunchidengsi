// 750_Number_Of_Corner_Rectangles
// map
class Solution {
public:
  int countCornerRectangles(vector<vector<int>> &grid) {
    int ans = 0;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> v(n);
    unordered_map<int, int> count;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (grid[i][j])
          v[i].push_back(j);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        for (int k = j + 1; k < v[i].size(); k++) {

          ans += count[v[i][j] * 201 + v[i][k]];
          count[v[i][j] * 201 + v[i][k]]++;
        }
      }
    }
    return ans;
  }
};
