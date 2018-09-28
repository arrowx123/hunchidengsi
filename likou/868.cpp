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
  int binaryGap(int N) {
    vector<int> digits(32);
    int d = 1;
    int ans = 0;

    for (int i = 0; i < 32; i++) {
      digits[i] = (N & d);
      N = (N >> 1);
    }

    for (int i = 0; i < (int)digits.size(); i++)
      cout << digits[i] << " ";
    cout << endl;

    int l = -1;
    for (int i = 0; i < 32; i++) {
      if (digits[i] == 1) {
        if (l == -1) {
          l = i;
        } else {
          ans = max(ans, i - l);
          l = i;
        }
      }
    }
    return ans;
  }
};
int main() {
  int N = 5;
  Solution solution = Solution();
  cout << solution.binaryGap(N);
  return 0;
}
