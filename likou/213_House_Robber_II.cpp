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
private:
  int helper(vector<int> &nums) {
    int len = nums.size();
    if (!len)
      return 0;
    vector<int> ans(len);
    for (int i = 0; i < len; i++) {
      if (i == 0 || i == 1)
        ans[i] = nums[i];
      else if (i == 2)
        ans[i] = nums[i] + ans[i - 2];
      else
        ans[i] = max(ans[i - 2], ans[i - 3]) + nums[i];
    }
    if (len == 1)
      return nums[0];
    else
      return max(ans[len - 1], ans[len - 2]);
  }

public:
  int rob(vector<int> &nums) {
    int len = nums.size();
    if (!len)
      return 0;
    else if (len == 1)
      return nums[0];
    vector<int> v1(nums.begin(), nums.begin() + len - 1);
    vector<int> v2(nums.begin() + 1, nums.begin() + len);
    return max(helper(v1), helper(v2));
  }
};
int main() {
  vector<int> nums = {1, 2};
  Solution solution;
  cout << solution.rob(nums);
  return 0;
}
