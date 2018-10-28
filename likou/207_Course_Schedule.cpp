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
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    int len = prerequisites.size();
    vector<int> indegree(numCourses);
    vector<vector<int>> adm(numCourses);
    for (int i = 0; i < len; i++) {
      adm[prerequisites[i].first].push_back(prerequisites[i].second);
      indegree[prerequisites[i].second]++;
    }

    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < numCourses; i++) {
      if (!indegree[i]) {
        q.push(i);
        cnt++;
      }
    }
    while (q.size()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < (int)adm[v].size(); i++) {
        indegree[adm[v][i]]--;
        if (!indegree[adm[v][i]]) {
          q.push(adm[v][i]);
          cnt++;
        }
      }
    }
    return cnt == numCourses;
  }
};
int main() {
  int numCourses = 2;
  vector<pair<int, int>> prerequisites = {{1, 0}};
  Solution solution;
  cout << solution.canFinish(numCourses, prerequisites);
  return 0;
}
