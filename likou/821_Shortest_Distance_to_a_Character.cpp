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
  vector<int> shortestToChar(string S, char C) {
    int l = INT_MIN;
    int r = INT_MAX;
    int size = S.size();

    for (int i = 0; i < size; i++) {
      if (S[i] == C) {
        l = i;
        break;
      }
    }

    vector<int> ans;
    for (int i = 0; i < size; i++) {
      if (S[i] == C) {
        ans.push_back(0);
        if (r != INT_MAX)
          l = r;
        for (int j = i + 1; j < size; j++) {
          if (S[j] == C) {
            r = j;
            break;
          }
        }
      } else {
        ans.push_back(min(abs(l - i), abs(r - i)));
      }
    }
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";
    return ans;
  }
};
int main() {
  Solution solution;

  string S = "loveleetcode";
  char C = 'e';
  solution.shortestToChar(S, C);
  return 0;
}
