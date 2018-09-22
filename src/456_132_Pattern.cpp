#include <algorithm>
#include <iostream>
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
  bool find132pattern(vector<int> &nums) {
    int len = nums.size();
    int l;
    int r;
    for (int i = 0; i < len - 2; i++) {
      for (int j = i + 1; j < len - 1; j++) {
        l = j;
        if (nums[l] > nums[i])
          break;
      }
      if (l == len - 1)
        continue;

      for (int j = l + 1; j < len; j++) {
        r = j;
        if (nums[r] >= nums[l]) {
          l = r;
        } else if (nums[r] > nums[i])
          return true;
      }
    }
    return false;
  }
};
int main() {
  //  vector<int> A = {3, 1, 4, 2};
  vector<int> A = {1, 2, 3, 4};
  Solution solution;
  cout << solution.find132pattern(A);
  return 0;
}
