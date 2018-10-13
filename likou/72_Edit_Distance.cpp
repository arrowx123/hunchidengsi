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
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> d(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
      d[i][0] = i;

    for (int i = 0; i <= n; i++)
      d[0][i] = i;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1])
          d[i][j] = d[i - 1][j - 1];
        else {
          d[i][j] =
              min(d[i - 1][j - 1] + 1, min(d[i - 1][j] + 1, d[i][j - 1] + 1));
        }
      }
    }
    return d[m][n];
  }
};
int main() {
  string word1 = "horse";
  string word2 = "ros";
  Solution solution;
  cout << solution.minDistance(word1, word2);
  return 0;
}
