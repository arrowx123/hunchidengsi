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
    stack<int> s;
    int ans = 0;
    int cur = 0;
    while (cur < (int)height.size()) {
      while (!s.empty() && height[cur] > height[s.top()]) {
        int top = s.top();
        s.pop();
        if (s.empty())
          break;

        int dis = cur - s.top() - 1;
        ans += dis * (min(height[cur], height[s.top()]) - height[top]);
      }
      s.push(cur++);
    }
    return ans;
  }
};
int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution solution;
  cout << solution.trap(height);
  return 0;
}
