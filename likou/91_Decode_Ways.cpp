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
  int numDecodings(string s) {
    int len = s.size();
    vector<int> cnt(len);

    if (s[len - 1] != '0')
      cnt[len - 1] = 1;
    if (len == 1)
      return cnt[0];

    if (stoi(s.substr(len - 2)) >= 10 && stoi(s.substr(len - 2)) <= 26)
      cnt[len - 2]++;
    if (s[len - 2] != '0')
      cnt[len - 2] += cnt[len - 1];

    for (int i = len - 3; i >= 0; i--) {
      int tenth = stoi(s.substr(i, 2));
      if (tenth >= 10 && tenth <= 26)
        cnt[i] += cnt[i + 2];
      if (s[i] != '0')
        cnt[i] += cnt[i + 1];
    }

    return cnt[0];
  }
};
int main() {
  string s = "10";
  Solution solution;
  cout << solution.numDecodings(s);
  return 0;
}
