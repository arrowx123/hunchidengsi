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
  string modify(string s) {
    int len = s.size();
    int i = 0;
    int j = len - 1;
    for (; i < len; i++) {
      if (s[i] != ' ')
        break;
    }

    for (; j >= 0; j--)
      if (s[j] != ' ')
        break;
    return s.substr(i, j - i + 1);
  }

public:
  bool isNumber(string s) {
    s = modify(s);
    int len = s.size();
    int sign_cnt = 0;
    int e_cnt = 0;
    int dot_cnt = 0;
    int num_cnt = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '-' || s[i] == '+') {
        sign_cnt++;
        if (sign_cnt > 1)
          return false;
        if (dot_cnt || num_cnt)
          return false;
      } else if (s[i] == 'e') {
        e_cnt++;
        if (e_cnt > 1)
          return false;
        sign_cnt = 0;
        if (!num_cnt)
          return false;
        num_cnt = 0;
        dot_cnt = 0;
      } else if (s[i] == '.') {
        dot_cnt++;
        if (dot_cnt > 1)
          return false;

        if (e_cnt)
          return false;
      } else if (s[i] == ' ') {
        if (sign_cnt || e_cnt || num_cnt || dot_cnt)
          return false;
        continue;
      } else if (s[i] >= '0' && s[i] <= '9')
        num_cnt++;
      else
        return false;
    }

    if (!num_cnt)
      return false;

    return true;
  }
};
int main() {
  string s = "1 ";
  Solution solution;
  cout << solution.isNumber(s);
  return 0;
}
