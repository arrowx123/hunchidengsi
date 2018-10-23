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
class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (!len)
      return s;

    vector<vector<int>> is_palindrome(len, vector<int>(len));
    for (int i = 0; i < len; i++) {
      is_palindrome[i][i] = true;
    }

    for (int i = 2; i <= len; i++) {
      for (int j = 0; j <= len - i; j++) {
        if (s[j] == s[j + i - 1] &&
            (j + 1 > j + i - 2 || is_palindrome[j + 1][j + i - 2])) {
          is_palindrome[j][j + i - 1] = true;
        }
      }
    }
    int max_len = 0;
    int l = -1;
    int r = -1;
    for (int i = 0; i < len; i++) {
      for (int j = i; j < len; j++) {
        if (j - i + 1 > max_len && is_palindrome[i][j]) {
          max_len = j - i + 1;
          l = i;
          r = j;
        }
      }
    }
    if (l == -1)
      return "";
    return s.substr(l, r - l + 1);
  }
};
int main() {
  string s = "a";
  Solution solution;
  cout << solution.longestPalindrome(s);
  return 0;
}
