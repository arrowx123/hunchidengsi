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
  bool backspaceCompare(string S, string T) {
    int len1 = S.size();
    int len2 = T.size();
    string s = "";
    string t = "";

    for (int i = 0; i < len1; i++) {
      if (S[i] != '#')
        s += S[i];
      else if (s.size() > 0)
        s.pop_back();
    }
    for (int i = 0; i < len2; i++) {
      if (T[i] != '#')
        t += T[i];
      else if (t.size() > 0)
        t.pop_back();
    }
    return s.compare(t) == 0;
  }
};
int main() {
  Solution solution;

  string S = "ab##";
  string T = "c#d#";
  cout << solution.backspaceCompare(S, T);
  return 0;
}
