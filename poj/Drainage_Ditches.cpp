#include <algorithm>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
#define SIZE 210

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
void read_input(int n, vector<vector<int>> &flow) {
  for (int i = 0; i < n; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    flow[l - 1][r - 1] += c;
  }
}
int solve(int m, vector<vector<int>> flow) {
  int ans = 0;

  while (true) {
    vector<bool> visited(m);
    vector<int> parent(m);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;

    while (q.size()) {
      int node = q.front();
      q.pop();
      if (node == m - 1)
        break;

      for (int i = 0; i < m; i++) {
        if (!visited[i] && flow[node][i] > 0) {
          q.push(i);
          parent[i] = node;
          visited[i] = true;
        }
      }
    }
    if (visited[m - 1]) {
      int path_flow = INT_MAX;
      int v = m - 1;
      while (true) {
        int u = parent[v];
        path_flow = min(path_flow, flow[u][v]);
        v = u;
        if (!v)
          break;
      }
      v = m - 1;
      while (true) {
        int u = parent[v];
        flow[u][v] -= path_flow;
        flow[v][u] += path_flow;
        v = u;
        if (!v)
          break;
      }
      ans += path_flow;
    } else
      break;
  }

  return ans;
}
int main() {
  int n;
  int m;
  vector<vector<int>> flow(SIZE, vector<int>(SIZE));
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        flow[i][j] = 0;
    read_input(n, flow);
    int ans = solve(m, flow);
    cout << ans << endl;
  }
  return 0;
}
