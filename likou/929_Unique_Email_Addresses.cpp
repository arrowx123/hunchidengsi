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
  int numUniqueEmails(vector<string> &emails) {
    int len = emails.size();
    unordered_set<string> uset;

    for (int i = 0; i < len; i++) {
      int l = emails[i].size();
      string tmp = "";
      bool before = true;
      for (int j = 0; j < l; j++) {
        if (emails[i][j] == '.' && before)
          continue;
        else if (emails[i][j] == '+') {
          while (emails[i][j] != '@')
            j++;
          j--;
          before = false;
        } else
          tmp += emails[i][j];
      }
      cout << "tmp: " << tmp << endl;
      uset.insert(tmp);
    }
    return uset.size();
  }
};
int main() {
  vector<string> emails = {"test.email+alex@leetcode.com",
                           "test.e.mail+bob.cathy@leetcode.com",
                           "testemail+david@lee.tcode.com"};
  Solution solution;
  cout << solution.numUniqueEmails(emails);
  return 0;
}
