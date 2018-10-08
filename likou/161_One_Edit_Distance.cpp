#include <algorithm>
#include <iostream>
#include <math.h>
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
private:
  bool check(string& s, string& t, int si, int ti, int d) {
    if (d > 1)
      return false;

    if (si < (int)s.size() && ti < (int)t.size()) {
      if (s[si] == t[ti]) {
        si++;
        ti++;
        return check(s, t, si, ti, d);
      } else {
        if (check(s, t, si + 1, ti, d + 1) || check(s, t, si, ti + 1, d + 1) ||
            check(s, t, si + 1, ti + 1, d + 1))
          return true;
        return false;
      }
    }

    if (abs((int)s.size() - 1 - si - ((int)t.size() - 1 - ti)) + d == 1)
      return true;
    return false;
  }

public:
  bool isOneEditDistance(string s, string t) { return check(s, t, 0, 0, 0); }
};
int main() {
  string s = "ab";
  string t = "acb";
  Solution solution;
  cout << solution.isOneEditDistance(s, t);
  return 0;
}
