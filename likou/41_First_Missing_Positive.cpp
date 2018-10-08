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
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (nums[i] <= 0 || nums[i] > len || nums[nums[i] - 1] == nums[i])
        continue;
      swap(nums[nums[i] - 1], nums[i]);
      i--;
    }
    int i = 0;
    for (; i < len; i++)
      if (nums[i] != i + 1) {
        break;
      }
    return i + 1;
  }
};
int main() {
  vector<int> nums = {};
  Solution solution;
  cout << solution.firstMissingPositive(nums);
  return 0;
}
