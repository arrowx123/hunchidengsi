// 445_Add_Two_Numbers_II
// linked_list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  int c = 0;
  int getLen(ListNode *node) {
    int len = 0;
    while (node) {
      len++;
      node = node->next;
    }
    return len;
  }

  ListNode *calc(ListNode *l1, ListNode *l2) {
    if (!l1)
      return nullptr;

    ListNode *node = new ListNode(0);
    node->next = calc(l1->next, l2->next);

    c = l1->val + l2->val + c;
    node->val = c % 10;
    c /= 10;
    return node;
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int m = getLen(l1);
    int n = getLen(l2);

    ListNode *l = m > n ? l1 : l2;
    ListNode *s = m > n ? l2 : l1;

    int diff = max(m, n) - min(m, n);
    ListNode *node = new ListNode(0);
    ListNode *tmp = node;
    while (diff--) {
      tmp->next = new ListNode(0);
      tmp = tmp->next;
    }

    tmp->next = s;
    ListNode *ret = calc(l, node->next);
    if (!c)
      return ret;

    ListNode *ans = new ListNode(c);
    ans->next = ret;
    return ans;
  }
};
