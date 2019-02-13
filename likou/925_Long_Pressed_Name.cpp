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
  bool isLongPressedName(string name, string typed) {
    int idx1 = 0;
    int idx2 = 0;
    int i = idx1;
    int j = idx2;

    while (i < (int)name.size() && j < (int)typed.size()) {
      for (; i < (int)name.size(); i++) {
        if (name[i] != name[idx1])
          break;
      }
      for (; j < (int)typed.size(); j++) {
        if (typed[j] != typed[idx2])
          break;
      }

      if (i - idx1 > j - idx2 || name[i] != typed[j])
        return false;
      idx1 = i;
      idx2 = j;
    }
    return true;
  }
};
int main() {
  Solution solution;

  string name = "alex";
  string typed = "aaleex";
  cout << solution.isLongPressedName(name, typed);
  return 0;
}
