#include <algorithm>
#include <iostream>
#include <map>
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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Robot {
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};
class Solution {
private:
  map<pair<string, string>, double> umap;
  unordered_map<string, vector<string>> conn;
  unordered_map<string, bool> visited;

  double calculate(string l, string r, double val) {
    //    cout << "l: " << l << " r: " << r << endl;
    if (umap.count(pair<string, string>(l, r))) {
      return val * umap[pair<string, string>(l, r)];
    } else {
      for (int i = 0; i < (int)conn[l].size(); i++) {
        string c = conn[l][i];
        if (visited[c])
          continue;
        visited[c] = true;
        double res = calculate(c, r, umap[pair<string, string>(l, c)]);
        if (res != -1) {
          return umap[pair<string, string>(l, r)] = val * res;
        }
      }
    }
    return umap[pair<string, string>(l, r)] = -1;
  }

public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double> &values,
                              vector<pair<string, string>> queries) {
    for (int i = 0; i < (int)equations.size(); i++) {
      string l = equations[i].first;
      string r = equations[i].second;
      umap[pair<string, string>(l, r)] = values[i];
      umap[pair<string, string>(r, l)] = 1 / values[i];
      conn[l].push_back(r);
      conn[r].push_back(l);
    }
    int len = queries.size();
    vector<double> ans;
    for (int i = 0; i < len; i++) {
      string l = queries[i].first;
      string r = queries[i].second;
      visited[l] = true;
      double v = calculate(l, r, 1);
      cout << v << endl;
      ans.push_back(v);
      visited.clear();
    }
    return ans;
  }
};
int main() {
  vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<pair<string, string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  Solution solution;
  solution.calcEquation(equations, values, queries);
  return 0;
}
