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
  void moveZeroes(vector<int> &nums) {
    int len = nums.size();
    int idx = 0;
    int i = 0;
    for (; i < len; i++) {
      if (nums[i])
        nums[idx++] = nums[i];
    }
    for (; idx < len; idx++)
      nums[idx] = 0;
  }
};
int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution solution;
  solution.moveZeroes(nums);
  return 0;
}
