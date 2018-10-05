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
  vector<int> plusOne(vector<int> &digits) {
    int len = digits.size();
    int add = 1;
    for (int i = len - 1; i >= 0; i--) {
      int d = digits[i] + add;
      digits[i] = d % 10;
      add = d / 10;
    }
    vector<int> ans;
    if (add)
      ans.push_back(add);
    for (int i = 0; i < len; i++)
      ans.push_back(digits[i]);
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";

    return ans;
  }
};
int main() {
  vector<int> digits = {4, 3, 2, 1};
  Solution solution;
  solution.plusOne(digits);
  return 0;
}
