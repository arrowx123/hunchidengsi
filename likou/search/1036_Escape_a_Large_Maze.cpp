// 1036_Escape_a_Large_Maze
// bfs
typedef pair<int, int> ii;
const vector<vector<int>> diff = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

class Solution {
public:
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                        vector<int> &target) {
    int sx = source[0], sy = source[1];
    int tx = target[0], ty = target[1];

    set<ii> seen;
    seen.insert({sx, sy});
    for (int i = 0; i < blocked.size(); i++)
      seen.insert({blocked[i][0], blocked[i][1]});

    queue<ii> que;
    que.push({sx, sy});
    int limit = 2e4;
    int n = 1e6;

    while (que.size() && limit--) {
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      if (ii{x, y} == ii{tx, ty})
        return true;

      for (int i = 0; i < diff.size(); i++) {
        int nx = x + diff[i][0];
        int ny = y + diff[i][1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
          continue;
        if (seen.count({nx, ny}))
          continue;

        que.push({nx, ny});
        seen.insert({nx, ny});
      }
    }
    if (limit > 0)
      return false;

    seen.clear();
    seen.insert({tx, ty});
    for (int i = 0; i < blocked.size(); i++)
      seen.insert({blocked[i][0], blocked[i][1]});
    while (que.size())
      que.pop();
    que.push({tx, ty});

    limit = 2e4;
    while (que.size() && limit--) {
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      if (ii{x, y} == ii{sx, sy})
        return true;

      for (int i = 0; i < diff.size(); i++) {
        int nx = x + diff[i][0];
        int ny = y + diff[i][1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
          continue;
        if (seen.count({nx, ny}))
          continue;

        que.push({nx, ny});
        seen.insert({nx, ny});
      }
    }
    return limit < 0;
  }
};
