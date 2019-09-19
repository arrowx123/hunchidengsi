// 272_Closest_Binary_Search_Tree_Value_II
// O(n)
// deque
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
  deque<int> deq;
  double target;
  int k;

  void rec(TreeNode *node) {
    if (!node)
      return;
    rec(node->left);

    deq.push_back(node->val);
    if (deq.size() > k) {
      if (abs(deq.back() - target) < abs(deq.front() - target))
        deq.pop_front();
      else
        deq.pop_back();
    }

    rec(node->right);
  }

public:
  vector<int> closestKValues(TreeNode *root, double tt, int kk) {
    target = tt;
    k = kk;
    rec(root);
    return vector<int>(deq.begin(), deq.end());
  }
};
