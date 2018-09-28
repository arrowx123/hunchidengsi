#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
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

class Solution {
private:
  bool dfs(int index, int c, unordered_map<int, int> &color,
           vector<vector<int>> &graph) {

    if (color.count(index))
      return color[index] == c;
		
		color[index] = c;
    for (int i = 0; i < (int)graph[index].size(); i++) {
      if (!dfs(graph[index][i], 1 - c, color, graph))
        return false;
    }

    return true;
  }

public:
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    int len = dislikes.size();
    vector<vector<int>> graph;
    unordered_map<int, int> color;
    graph.resize(N + 1);

    for (int i = 0; i < len; i++) {
      int l = dislikes[i][0];
      int r = dislikes[i][1];
      graph[l].push_back(r);
      graph[r].push_back(l);
    }

    for (int i = 1; i <= N; i++) {
      if (!color.count(i) && !dfs(i, 0, color, graph))
        return false;
    }
    return true;
  }
};

int main() {
  int N = 5;
  vector<vector<int>> dislikes = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
  Solution solution = Solution();
  cout << solution.possibleBipartition(N, dislikes);
  return 0;
}
