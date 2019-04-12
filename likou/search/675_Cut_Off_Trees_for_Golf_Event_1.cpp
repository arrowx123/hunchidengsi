// hadlock
struct pos {
  int x;
  int y;
  int detour;
};

struct tree {
  int x;
  int y;
  int height;
};

bool cmp(tree p1, tree p2) { return p1.height < p2.height; }

class Solution {
private:
  vector<pair<int, int>> offset = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

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

      deque<pos> deq;
      deq.push_front({initX, initY, 0});
      vector<vector<bool>> visited(m, vector<bool>(n));
      bool find = false;

      while (deq.size()) {
        int x = deq.front().x;
        int y = deq.front().y;
        int detour = deq.front().detour;
        deq.pop_front();

        if (x == toCut[i].x && y == toCut[i].y) {
          find = true;
          ans += detour * 2 + abs(x - initX) + abs(y - initY);
          initX = x;
          initY = y;
          break;
        }

        if (visited[x][y])
          continue;

        visited[x][y] = true;
        for (int j = 0; j < offset.size(); j++) {
          int cx = x + offset[j].first;
          int cy = y + offset[j].second;

          if (cx >= 0 && cx < m && cy >= 0 && cy < n && forest[cx][cy]) {
            if (abs(cx - toCut[i].x) + abs(cy - toCut[i].y) >
                abs(x - toCut[i].x) + abs(y - toCut[i].y))
              deq.push_back({cx, cy, detour + 1});
            else
              deq.push_front({cx, cy, detour});
          }
        }
      }
      if (!find)
        return -1;
    }
    return ans;
  }
};
