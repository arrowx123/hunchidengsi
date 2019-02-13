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
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    if (nums[l] == target)
      return l;
    else
      return -1;
  }
};
int main() {
  Solution solution;

  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  cout << solution.search(nums, target);
  return 0;
}
