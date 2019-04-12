// bfs
struct pos {
  int x;
  int y;
  int step;
};

struct tree {
  int x;
  int y;
  int height;
};

bool cmp(tree p1, tree p2) { return p1.height < p2.height; }

class Solution {
private:
  vector<pair<int, int>> offset = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

public:
  int cutOffTree(vector<vector<int>> &forest) {
    int m = forest.size();
    int n = forest[0].size();
    vector<tree> toCut;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (forest[i][j] > 1)
          toCut.push_back({i, j, forest[i][j]});
      }
    }

    sort(toCut.begin(), toCut.end(), cmp);
    int initX = 0;
    int initY = 0;
    int ans = 0;
    for (int i = 0; i < toCut.size(); i++) {

      queue<pos> que;
      que.push({initX, initY, 0});
      vector<vector<bool>> visited(m, vector<bool>(n));
      bool find = false;
      while (que.size()) {
        int x = que.front().x;
        int y = que.front().y;
        int step = que.front().step;
        que.pop();

        if (x == toCut[i].x && y == toCut[i].y) {
          initX = x;
          initY = y;
          find = true;
          ans += step;
          break;
        }

        for (int j = 0; j < offset.size(); j++) {
          int cx = x + offset[j].first;
          int cy = y + offset[j].second;

          if (cx >= 0 && cx < m && cy >= 0 && cy < n && forest[cx][cy] &&
              !visited[cx][cy]) {
            que.push({cx, cy, step + 1});
            visited[cx][cy] = true;
          }
        }
      }
      if (!find)
        return -1;
    }
    return ans;
  }
};
