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
private:
  vector<int> get_lps(string s) {
    int len = s.size();
    vector<int> lps(len);

    for (int i = 1; i < len; i++) {
      int t = lps[i - 1];
      while (t > 0 && s[i] != s[t])
        t = lps[t - 1];
      if (s[i] == s[t])
        t++;
      lps[i] = t;
    }
    return lps;
  }

public:
  string shortestPalindrome(string s) {
    if (s == "")
      return s;

    string sc = s;
    reverse(s.begin(), s.end());
    string tmp = sc + s;

    vector<int> lps = get_lps(tmp);
    int idx = tmp.size();
    while (idx > (int)sc.size()) {
      idx = lps[idx - 1];
    }

    string begin = sc.substr(idx);
    reverse(begin.begin(), begin.end());

    return begin + sc;
  }
};
int main() {
  //  string s = "aacecaaa";
  string s = "aabba";
  Solution solution;
  cout << solution.shortestPalindrome(s);
  return 0;
}
