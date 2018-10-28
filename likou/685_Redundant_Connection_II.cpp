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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int len = edges.size();
    vector<int> ans;
    vector<int> indegree(len + 1);
    vector<int> outdegree(len + 1);
    vector<vector<int>> out(len + 1);
    vector<vector<int>> in(len + 1);
    int mc = -1;
    for (int i = 0; i < len; i++) {
      int l = edges[i][0];
      int r = edges[i][1];
      out[l].push_back(r);
      in[r].push_back(l);
      indegree[r]++;
      if (indegree[r] > 1)
        mc = r;
      outdegree[l]++;
    }

    queue<int> qin;
    queue<int> qout;
    for (int i = 1; i <= len; i++) {
      if (!indegree[i])
        qin.push(i);
      else if (!outdegree[i])
        qout.push(i);
    }
    while (qin.size()) {
      int node = qin.front();
      qin.pop();

      for (int i = 0; i < (int)out[node].size(); i++) {
        indegree[out[node][i]]--;
        if (!indegree[out[node][i]])
          qin.push(out[node][i]);
      }
    }
    int circle = -1;
    for (int i = 1; i <= len; i++) {
      if (indegree[i]) {
        circle = i;
        break;
      }
    }

    if (circle != -1) {
      while (qout.size()) {
        int node = qout.front();
        qout.pop();
        for (int i = 0; i < (int)in[node].size(); i++) {
          outdegree[in[node][i]]--;
          indegree[node]--;
          if (!outdegree[in[node][i]])
            qout.push(in[node][i]);
        }
      }
    }

    if (mc == -1 && circle != -1) {
      for (int i = len - 1; i >= 0; i--) {
        if (indegree[edges[i][0]] && indegree[edges[i][1]]) {
          ans = edges[i];
          break;
        }
      }
    } else if (mc != -1 && circle == -1) {
      for (int i = len - 1; i >= 0; i--) {
        if (edges[i][1] == mc) {
          ans = edges[i];
          break;
        }
      }
    } else {
      for (int i = len - 1; i >= 0; i--) {
        if (edges[i][1] == mc && indegree[edges[i][0]]) {
          ans = edges[i];
          break;
        }
      }
    }
    cout << ans[0] << " " << ans[1];
    return ans;
  }
};
int main() {
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  Solution solution;
  solution.findRedundantDirectedConnection(edges);
  return 0;
}
