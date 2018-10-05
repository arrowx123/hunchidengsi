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
  string addBoldTag(string s, vector<string> &dict) {
    int len = s.size();
    vector<int> mark(len);
    for (int i = 0; i <= len; i++) {
      for (int j = 0; j < (int)dict.size(); j++) {
        int k = 0;
        for (; k < (int)dict[j].size(); k++) {
          if (i + k >= len || s[i + k] != dict[j][k])
            break;
        }
        if (k == (int)dict[j].size()) {
          for (k = 0; k < (int)dict[j].size(); k++) {
            mark[i + k] = 1;
          }
        }
      }
    }

    string ans = "";
    for (int i = 0; i < len; i++) {
      if (i == 0 && mark[i])
        ans += "<b>";
      if (i > 0 && mark[i] && !mark[i - 1])
        ans += "<b>";

      ans += s[i];

      if (i == len - 1 && mark[i])
        ans += "</b>";
      if (i < len - 1 && mark[i] && !mark[i + 1])
        ans += "</b>";
    }
    return ans;
  }
};
int main() {
  string s = "aaabbcc";
  vector<string> dict = {"aaa", "aab", "bc"};
  Solution solution;
  cout << solution.addGBoldTag(s, dict);
  return 0;
}
