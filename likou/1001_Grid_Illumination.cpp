#include <algorithm>
#include <iostream>
#include <math.h>
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
typedef pair<int, int> ii;
class Solution {
private:
  vector<vector<int>> neighbors = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                                   {0, -1},  {1, -1}, {1, 0},  {1, 1}};

public:
  vector<int> gridIllumination(int N, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {
    vector<int> ans;
    unordered_map<int, int> rows;
    unordered_map<int, int> columns;
    unordered_map<int, int> left_diag;
    unordered_map<int, int> right_diag;
    set<ii> my_set;

    for (auto ele : lamps) {
      int l = ele[0];
      int r = ele[1];

      rows[l]++;
      columns[r]++;
      left_diag[l - r + N - 1]++;
      right_diag[l + r]++;
      my_set.insert({l, r});
    }

    for (auto ele : queries) {
      int l = ele[0];
      int r = ele[1];
      if (rows[l] || columns[r] || left_diag[l - r + N - 1] ||
          right_diag[l + r])
        ans.push_back(1);
      else
        ans.push_back(0);

      for (int i = 0; i < (int)neighbors.size(); i++) {
        int x = l + neighbors[i][0];
        int y = r + neighbors[i][1];

        if (my_set.count({x, y})) {
          rows[x]--;
          columns[y]--;
          left_diag[x - y + N - 1]--;
          right_diag[x + y]--;
          my_set.erase({x, y});
        }
      }
    }
    return ans;
  }
};
int main() {
  Solution solution;
  int N = 5;
  vector<vector<int>> lamps = {{0, 0}, {4, 4}};
  vector<vector<int>> queries = {{1, 1}, {1, 0}};
  solution.gridIllumination(N, lamps, queries);
  return 0;
}
