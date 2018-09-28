#include <algorithm>
#include <stdio.h>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *h = head;
    int length = 0;

    while (head) {
      length++;
      head = head->next;
    }

    int idx = (length / 2) + 1;
    for (int i = 0; i < idx - 1; i++) {
      h = h->next;
    }
    return h;
  };
};

int main() { return 0; }
