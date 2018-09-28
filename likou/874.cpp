#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> xs = {0, 1, 0, -1};
  vector<int> ys = {1, 0, -1, 0};

public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int len = commands.size();
    int dir = 0;
    set<pair<int, int>> uset;
    int x = 0;
    int y = 0;
    int ans = 0;

    for (int i = 0; i < (int)obstacles.size(); i++) {
      uset.insert({obstacles[i][0], obstacles[i][1]});
    }

    for (int i = 0; i < len; i++) {
      if (commands[i] == -1) {
        dir = (dir + 1) % 4;
      } else if (commands[i] == -2) {
        dir = (dir + 3) % 4;
      } else {
        for (int j = 0; j < commands[i]; j++) {
          int nx = x + xs[dir];
          int ny = y + ys[dir];

          if (uset.find({nx, ny}) == uset.end()) {
            x = nx;
            y = ny;
            ans = max(ans, x * x + y * y);
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<int> commands = {4, -1, 3};
  vector<vector<int>> obstacles;
  Solution solution = Solution();
  cout << solution.robotSim(commands, obstacles);

  return 0;
}
