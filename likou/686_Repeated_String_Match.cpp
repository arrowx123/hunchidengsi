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
private:
  int KMP(string a, string b) {
    int len = b.size();
    vector<int> lps(len);

    int idx = 0;
    int i = 1;
    while (i < len) {
      if (b[i] == b[idx]) {
        idx++;
        lps[i] = idx;
        i++;
      } else {
        if (idx)
          idx = lps[idx - 1];
        else {
          lps[i] = 0;
          i++;
        }
      }
    }

    idx = 0;
    vector<int> ans;
    i = 0;
    while (i < (int)a.size()) {
      if (a[i] == b[idx]) {
        i++;
        idx++;
      } else {
        if (idx)
          idx = lps[idx - 1];
        else
          i++;
      }
      if (idx == len) {
        ans.push_back(i - 1);
        idx = lps[idx - 1];
      }
    }
    return ans.size();
  }

public:
  int repeatedStringMatch(string A, string B) {
    int m = (B.size() - 1) / A.size() + 1;
    string tmp = A;
    for (int i = 0; i < m - 1; i++)
      tmp.append(A);

    if (KMP(tmp, B))
      return m;

    tmp.append(A);
    if (KMP(tmp, B))
      return m + 1;

    return -1;
  }
};

int main() {
  string A = "a";
  string B = "aa";
  Solution solution;
  cout << solution.repeatedStringMatch(A, B);

  return 0;
}
