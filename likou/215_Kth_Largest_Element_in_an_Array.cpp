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
  int findKthLargest(vector<int> &nums, int k) {
    int len = nums.size();
    int ans = -1;
    int l = 0;
    int r = len - 1;

    while (true) {
      int pivot = nums[r];
      int idx = l;
      for (int i = l; i < r; i++) {
        if (nums[i] <= pivot) {
          swap(nums[idx++], nums[i]);
        }
      }
      swap(nums[idx], nums[r]);
      if (idx + k == len) {
        ans = nums[idx];
        break;
      } else if (idx + k < len) {
        l = idx + 1;
      } else {
        r = idx - 1;
      }
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  Solution solution;
  cout << solution.findKthLargest(nums, k);
  return 0;
}
