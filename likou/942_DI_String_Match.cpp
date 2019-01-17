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
  vector<int> diStringMatch(string S) {
    vector<int> ans;
    ans.push_back(0);

    int low = -1;
    int high = 1;

    int len = S.size();
    for (int i = len - 1; i >= 0; i--) {
      if (S[i] == 'I') {
        ans.push_back(low);
        low--;
      } else {
        ans.push_back(high);
        high++;
      }
    }
    reverse(ans.begin(), ans.end());

    int min_ = INT_MAX;
    for (int i = 0; i < (int)ans.size(); i++)
      if (ans[i] < min_)
        min_ = ans[i];

    for (int i = 0; i < (int)ans.size(); i++)
      ans[i] -= min_;

    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";
    return ans;
  }
};
int main() {
  string S = "III";
  Solution solution;
  solution.diStringMatch(S);
  return 0;
}
