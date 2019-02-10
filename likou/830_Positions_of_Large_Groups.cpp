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
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> ans;
    int len = S.size();
    int l = 0;
    int r = 0;
    while (r < len) {
      if (S[r] != S[l]) {
        if (r - l >= 3) {
          ans.push_back({l, r - 1});
        }
        l = r;
      } else {
        r++;
      }
    }
    if (r - l >= 3) {
      ans.push_back({l, r - 1});
    }
    return ans;
  }
};
int main() {
  Solution solution;

  string S = "abbxxxxzzy";
  solution.largeGroupPositions(S);
  return 0;
}
