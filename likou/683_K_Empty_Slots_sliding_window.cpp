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
  int kEmptySlots(vector<int> &flowers, int k) {
    int len = flowers.size();
    vector<int> date(len);

    for (int i = 0; i < len; i++) {
      date[flowers[i] - 1] = i;
    }
    int ans = len;
    int l = 0;
    int r = 0;
    while (l <= len - 1 - k - 1) {
      for (r = l + 1; r < l + k + 1; r++) {
        if (date[r] < date[l] || date[r] < date[l + k + 1]) {
          l = r;
          break;
        }
      }
      if (r == l + k + 1) {
        ans = min(ans, max(date[l], date[l + k + 1]));
        l = l + k + 1;
      }
    }
    if (ans != len)
      return ans + 1;
    else
      return -1;
  }
};

int main() {
  vector<int> flowers = {10, 1, 6, 4, 2, 8, 9, 7, 5, 3};
  int k = 1;
  Solution solution;
  cout << solution.kEmptySlots(flowers, k);
  return 0;
}
