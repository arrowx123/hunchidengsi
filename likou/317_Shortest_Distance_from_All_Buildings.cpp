#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};
class Solution {
public:
  int shortestDistance(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> total = grid;
    vector<int> diff = {-1, 0, 1, 0, -1};
    int walk = 0;
    int ans = -1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          ans = -1;
          queue<pair<int, int>> q;
          q.emplace(i, j);
          vector<vector<int>> dist = grid;

          while (q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
              int cx = x + diff[k];
              int cy = y + diff[k + 1];

              if (cx >= 0 && cx < m && cy >= 0 && cy < n &&
                  grid[cx][cy] == walk) {
                grid[cx][cy]--;
                q.emplace(cx, cy);
                dist[cx][cy] = dist[x][y] + 1;
                total[cx][cy] += dist[cx][cy] - 1;
                if (ans < 0 || ans > total[cx][cy])
                  ans = total[cx][cy];
              }
            }
          }
          walk--;
        }
      }
    }

    return ans;
  }
};
int main() {
  vector<vector<int>> grid = {
      {1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
  Solution solution;
  cout << solution.shortestDistance(grid);
  return 0;
}
