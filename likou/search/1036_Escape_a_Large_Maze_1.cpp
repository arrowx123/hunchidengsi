// 1036_Escape_a_Large_Maze
// bfs
typedef pair<int, int> ii;
vector<vector<int>> diff = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

int R;
int C;
vector<int> rows;
vector<int> cols;
set<ii> block;

int compressRow(int x) {
  return lower_bound(rows.begin(), rows.end(), x) - rows.begin();
}

int compressCol(int x) {
  return lower_bound(cols.begin(), cols.end(), x) - cols.begin();
}

bool bfs(int sx, int sy, int tx, int ty) {
  queue<ii> que;
  set<ii> seen;
  que.push({sx, sy});
  seen.insert({sx, sy});

  while (que.size()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    if (ii{x, y} == ii{tx, ty})
      return true;

    for (int i = 0; i < diff.size(); i++) {
      int nx = x + diff[i][0];
      int ny = y + diff[i][1];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C || seen.count({nx, ny}) ||
          block.count({nx, ny}))
        continue;
      seen.insert({nx, ny});
      que.push({nx, ny});
    }
  }
  return false;
}

class Solution {
public:
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                        vector<int> &target) {

    rows = {};
    cols = {};
    block.clear();

    int sx = source[0], sy = source[1];
    int tx = target[0], ty = target[1];

    rows.push_back(sx);
    rows.push_back(tx);
    rows.push_back(0);
    rows.push_back(1e6);

    cols.push_back(sy);
    cols.push_back(ty);
    cols.push_back(0);
    cols.push_back(1e6);

    for (int i = 0; i < blocked.size(); i++) {
      int x = blocked[i][0];
      int y = blocked[i][1];

      rows.push_back(x);
      cols.push_back(y);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    rows.resize(unique(rows.begin(), rows.end()) - rows.begin());
    cols.resize(unique(cols.begin(), cols.end()) - cols.begin());

    R = rows.size();
    C = cols.size();

    for (int i = 0; i < blocked.size(); i++) {
      int x = compressRow(blocked[i][0]);
      int y = compressCol(blocked[i][1]);
      block.insert({x, y});
    }

    return bfs(compressRow(sx), compressCol(sy), compressRow(tx),
               compressCol(ty));
  }
};
