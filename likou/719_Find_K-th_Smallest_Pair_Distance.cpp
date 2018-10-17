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
  int smallestDistancePair(vector<int> &nums, int k) {
    int len = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums[len - 1];
    int w = 2 * r;
    vector<int> dup(len);
    vector<int> pre(w);

    for (int i = 1; i < len; i++)
      if (nums[i] == nums[i - 1])
        dup[i] = 1 + dup[i - 1];

    int left = 0;
    for (int i = 0; i < w; i++) {
      while (left < len && nums[left] == i)
        left++;
      pre[i] = left;
    }

    while (l < r) {
      int mid = (l + r) / 2;
      int count = 0;

      for (int i = 0; i < len; i++) {
        count += pre[nums[i] + mid] - pre[nums[i]] + dup[i];
      }

      if (count >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
int main() {
  vector<int> nums = {1, 3, 1};
  int k = 1;
  Solution solution;
  cout << solution.smallestDistancePair(nums, k);
  return 0;
}
