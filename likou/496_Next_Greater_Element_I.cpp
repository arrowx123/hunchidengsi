#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
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
  vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
    vector<int> ans;
    unordered_map<int, int> pos;
    int len1 = findNums.size();
    int len2 = nums.size();

    for (int i = 0; i < len2; i++) {
      pos[nums[i]] = i;
    }

    for (int i = 0; i < len1; i++) {
      int j = pos[findNums[i]];
      for (; j < len2; j++) {
        if (nums[j] > findNums[i])
          break;
      }
      if (j < len2)
        ans.push_back(nums[j]);
      else
        ans.push_back(-1);
    }
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";
    return ans;
  }
};
int main() {
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  Solution solution;
  solution.nextGreaterElement(nums1, nums2);
  return 0;
}
