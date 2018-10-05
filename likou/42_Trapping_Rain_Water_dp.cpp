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
    vector<int> left_most(len);
    vector<int> right_most(len);

    for (int i = 1; i < len; i++) {
      left_most[i] = max(left_most[i - 1], height[i - 1]);
    }
    for (int i = len - 2; i >= 0; i--) {
      right_most[i] = max(right_most[i + 1], height[i + 1]);
    }

    for (int i = 0; i < len; i++) {
      ans += max(0, min(left_most[i], right_most[i]) - height[i]);
    }

    return ans;
  }
};
int main() {
  vector<int> height = {0, 2, 0};
  Solution solution;
  cout << solution.trap(height);
  return 0;
}
