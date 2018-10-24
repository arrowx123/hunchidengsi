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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
private:
  int cal(int x, int a, int b, int c) { return a * x * x + b * x + c; }

public:
  vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
    int len = nums.size();
    vector<int> ans;
    if (a <= 0) {
      int l = 0;
      int r = len - 1;

      while (l <= r) {
        if (cal(nums[l], a, b, c) <= cal(nums[r], a, b, c)) {
          ans.push_back(cal(nums[l], a, b, c));
          l++;
        } else {
          ans.push_back(cal(nums[r], a, b, c));
          r--;
        }
      }
    } else {
      int l = 0;
      int r = len - 1;

      while (l <= r) {
        if (cal(nums[l], a, b, c) >= cal(nums[r], a, b, c)) {
          ans.push_back(cal(nums[l], a, b, c));
          l++;
        } else {
          ans.push_back(cal(nums[r], a, b, c));
          r--;
        }
      }
      reverse(ans.begin(), ans.end());
    }
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " ";
    }
    return ans;
  }
};
int main() {
  vector<int> nums = {-4, -2, 2, 4};
  int a = 1;
  int b = 3;
  int c = 5;
  Solution solution;
  solution.sortTransformedArray(nums, a, b, c);
  return 0;
}
