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
  int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> trusted(N + 1);
    vector<int> trusting(N + 1);

    for (auto ele : trust) {
      int l = ele[0];
      int r = ele[1];

      trusted[r]++;
      trusting[l]++;
    }

    int ans = -1;
    for (int i = 1; i <= N; i++) {
      if (trusted[i] == N - 1 && !trusting[i]) {

        ans = i;
        break;
      }
    }
    return ans;
  }
};
int main() {
  Solution solution;

  return 0;
}
