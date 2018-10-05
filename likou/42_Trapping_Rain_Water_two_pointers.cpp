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
  int trap(vector<int> &height) {
    int ans = 0;
    int len = height.size();
    int l = 0;
    int r = len - 1;
    int left_max = 0;
    int right_max = 0;

    while (l < r) {
      if (height[l] < height[r]) {
        left_max = max(left_max, height[l++]);
        ans += max(0, left_max - height[l]);
      } else {
        right_max = max(right_max, height[r--]);
        ans += max(0, right_max - height[r]);
      }
    }
    return ans;
  }
};
int main() {
  //  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> height = {0, 2, 0};
  Solution solution;
  cout << solution.trap(height);
  return 0;
}
