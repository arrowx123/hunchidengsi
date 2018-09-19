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
  bool buddyStrings(string A, string B) {
    int lena = A.size();
    int lenb = B.size();

    if (lena != lenb)
      return false;

    if (A.compare(B) == 0) {
      vector<int> cnt(26);
      for (int i = 0; i < lena; i++) {
        cnt[A[i] - 'a']++;
        if (cnt[A[i] - 'a'] > 1)
          return true;
      }
			return false;
    }

    int l = -1;
    int r = -1;
    for (int i = 0; i < lena; i++) {
      if (A[i] != B[i]) {
        if (l == -1)
          l = i;
        else if (r == -1)
          r = i;
        else
          return false;
      }
    }
    if (A[l] == B[r] && A[r] == B[l])
      return true;
    return false;
  }
};
int main() {
  string A = "ab";
  string B = "ab";
  Solution solution;
  cout << solution.buddyStrings(A, B);
  return 0;
}
