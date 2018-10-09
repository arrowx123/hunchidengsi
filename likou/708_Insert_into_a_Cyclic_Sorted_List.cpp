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
  Node *insert(Node *head, int insertVal) {
    Node *res = new Node();
    if (!head) {
      res->val = insertVal;
      res->next = res;

    } else {
      res = head;
      while (true) {
        Node *next = head->next;
        if ((insertVal >= head->val && insertVal <= next->val &&
             head->val <= next->val) ||
            (head->val >= next->val &&
             ((insertVal <= next->val) || (insertVal >= head->val)))) {
          Node *tmp = new Node(insertVal, next);
          head->next = tmp;
          break;
        } else {
          head = head->next;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution solution;
  return 0;
}
