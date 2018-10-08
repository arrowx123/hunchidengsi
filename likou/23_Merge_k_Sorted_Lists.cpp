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
class Solution {
private:
  ListNode *mergeList(ListNode *a, ListNode *b) {
    ListNode *head = new ListNode(0);
    ListNode *re = head;
    while (true) {
      if (a == NULL || b == NULL)
        break;
      if (a->val < b->val) {
        head->next = a;
        a = a->next;
      } else {
        head->next = b;
        b = b->next;
      }
      head = head->next;
    }

    if (a == NULL) {
      head->next = b;
    } else if (b == NULL) {
      head->next = a;
    }
    return re->next;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return NULL;
    int gap = 2;
    int len = lists.size();
    while (gap / 2 < len) {
      for (int i = 0; i < len; i += gap) {
        if (i + gap / 2 < len) {
          lists[i] = mergeList(lists[i], lists[i + gap / 2]);
        }
      }
      gap *= 2;
    }
    return lists[0];
  }
};

int main() {
  Solution solution;
  return 0;
}
