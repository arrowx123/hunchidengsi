/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> v;
    while (head) {
      v.push_back(head->val);
      head = head->next;
    }

    vector<int> ans(v.size(), 0);
    stack<int> st;
    for (int i = v.size() - 1; i >= 0; i--) {
      while (st.size() && v[i] >= st.top())
        st.pop();

      if (st.size())
        ans[i] = st.top();

      st.push(v[i]);
    }
    return ans;
  }
};
