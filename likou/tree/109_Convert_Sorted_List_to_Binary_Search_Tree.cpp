// 109_Convert_Sorted_List_to_Binary_Search_Tree
// tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  ListNode *node;
  TreeNode *traverse(int l, int r) {
    if (l > r)
      return nullptr;

    int mid = (l + r) / 2;
    TreeNode *left = traverse(l, mid - 1);
    TreeNode *cur = new TreeNode(node->val);
    node = node->next;
    TreeNode *right = traverse(mid + 1, r);

    cur->left = left;
    cur->right = right;
    return cur;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    ListNode *cp = head;
    int len = 0;
    while (cp) {
      len++;
      cp = cp->next;
    }

    node = head;
    return traverse(0, len - 1);
  }
};
