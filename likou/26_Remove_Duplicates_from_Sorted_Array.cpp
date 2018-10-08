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
  int removeDuplicates(vector<int> &nums) {
    int len = nums.size();
		if(!len)
			return 0;
    int idx = 0;
    for (int i = 1; i < len; i++) {
      if (nums[i] != nums[idx]) {
        idx++;
        nums[idx] = nums[i];
      }
    }
    return idx + 1;
  }
};
int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution solution;
  cout << solution.removeDuplicates(nums);
  return 0;
}
