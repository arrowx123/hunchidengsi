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
private:
  vector<int> offset = {-1, 0, 1, 0, -1};

public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
    vector<pair<int, int>> ans;
    int m = matrix.size();
    if (!m)
      return ans;
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        vector<vector<int>> visited(m, vector<int>(n));
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        bool pacific = false;
        bool atlantic = false;

        while (q.size()) {
          pair<int, int> p = q.front();
          q.pop();

          if (p.first == 0 || p.second == 0)
            pacific = true;
          if (p.first == m - 1 || p.second == n - 1)
            atlantic = true;

          if (pacific && atlantic)
            break;

          for (int k = 0; k < 4; k++) {
            int nx = p.first + offset[k];
            int ny = p.second + offset[k + 1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
              continue;
            if (matrix[nx][ny] > matrix[p.first][p.second])
              continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
          }
        }
        if (pacific && atlantic)
          ans.push_back({i, j});
      }
    }
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
    return ans;
  }
};

int main() {
  vector<vector<int>> matrix = {{12, 7, 7, 14, 6, 17, 12, 17, 8, 18, 9, 5},
                                {6, 8, 12, 5, 3, 6, 2, 14, 19, 6, 18, 13},
                                {0, 6, 3, 8, 8, 10, 8, 17, 13, 13, 13, 12},
                                {5, 6, 8, 8, 15, 16, 19, 14, 7, 11, 2, 3},
                                {7, 18, 2, 7, 10, 10, 3, 14, 13, 15, 15, 7},
                                {18, 6, 19, 4, 12, 3, 3, 2, 6, 6, 19, 6},
                                {3, 18, 5, 16, 19, 6, 3, 12, 6, 0, 14, 11},
                                {9, 10, 17, 12, 10, 11, 11, 9, 0, 0, 12, 0},
                                {4, 13, 3, 0, 4, 12, 9, 5, 6, 17, 10, 11},
                                {18, 3, 5, 0, 8, 19, 18, 4, 8, 19, 1, 3},
                                {16, 2, 14, 6, 4, 14, 7, 2, 9, 7, 13, 18},
                                {0, 16, 19, 16, 16, 4, 15, 19, 7, 0, 3, 16},
                                {13, 8, 12, 8, 2, 3, 5, 18, 6, 15, 18, 6},
                                {4, 10, 8, 1, 16, 0, 6, 0, 14, 10, 11, 8},
                                {7, 1, 3, 4, 11, 12, 9, 0, 6, 2, 17, 5},
                                {1, 16, 6, 1, 0, 19, 11, 1, 5, 7, 8, 2},
                                {4, 1, 14, 13, 14, 7, 3, 7, 1, 9, 15, 18},
                                {14, 11, 6, 14, 14, 14, 4, 0, 11, 17, 1, 9},
                                {3, 14, 2, 10, 3, 1, 9, 16, 1, 13, 0, 15},
                                {8, 9, 13, 5, 5, 7, 10, 1, 4, 5, 0, 9},
                                {13, 16, 15, 5, 17, 6, 16, 13, 5, 7, 3, 15},
                                {5, 1, 12, 19, 3, 13, 0, 0, 3, 10, 6, 13},
                                {12, 17, 9, 16, 16, 6, 2, 6, 12, 15, 14, 16},
                                {7, 7, 0, 6, 4, 15, 1, 7, 17, 5, 2, 12},
                                {3, 17, 0, 2, 4, 5, 11, 7, 16, 16, 16, 13},
                                {3, 7, 16, 11, 2, 16, 14, 9, 16, 17, 10, 3},
                                {12, 18, 17, 17, 5, 15, 1, 2, 12, 12, 5, 7},
                                {11, 10, 10, 0, 11, 7, 17, 14, 5, 15, 2, 16},
                                {7, 19, 14, 7, 6, 2, 4, 16, 11, 19, 14, 14},
                                {6, 17, 6, 6, 6, 15, 9, 12, 8, 13, 1, 7},
                                {16, 3, 15, 0, 18, 17, 0, 11, 3, 16, 11, 12},
                                {15, 12, 4, 6, 19, 15, 17, 7, 3, 9, 2, 11}};
  Solution solution;
  solution.pacificAtlantic(matrix);
  return 0;
}
