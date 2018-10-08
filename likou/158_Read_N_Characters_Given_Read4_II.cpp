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
private:
  int i = 0;
  int len = 0;
  char tmp[4];

public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int idx = 0;
    while (idx < n) {
      if (i == len) {
        i = 0;
        len = read4(tmp);
        if (!len)
          break;
      }
      buf[idx++] = tmp[i++];
    }
    return idx;
  }
};
int main() {
  Solution solution;
  return 0;
}
