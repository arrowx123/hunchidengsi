#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
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
  bool isMonotonic(vector<int> &A) {
    int len = A.size();
    int i = 1;
    for (i = 1; i < len; i++) {
      if (A[i] >= A[i - 1])
        continue;
      else
        break;
    }
    if (i == len)
      return true;

    i = 1;
    for (i = 1; i < len; i++) {
      if (A[i] <= A[i - 1])
        continue;
      else
        break;
    }
    if (i == len)
      return true;

    return false;
  }
};
int main() {
  vector<int> A = {1, 3, 2};
  Solution solution = Solution();
  cout << solution.isMonotonic(A);
  return 0;
}
