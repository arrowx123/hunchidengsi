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
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int idx = 0;
    while (idx < n) {
      char tmp[4];
      int len = read4(tmp);

      for (int i = 0; i < len; i++) {
        buf[idx++] = tmp[i];
        if (idx == n)
          break;
      }
      if (len < 4)
        break;
    }
    return idx;
  }
};
int main() {
  Solution solution;
  return 0;
}
