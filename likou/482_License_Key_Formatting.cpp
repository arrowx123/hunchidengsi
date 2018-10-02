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
  string licenseKeyFormatting(string S, int K) {
    int len = S.size();
    string input = "";
    for (int i = 0; i < len; i++) {
      if (S[i] != '-') {
        if (S[i] >= 'a' && S[i] <= 'z')
          S[i] = S[i] - 'a' + 'A';
        input += S[i];
      }
    }

    string ans = "";
    len = input.size();
    int mod = len % K;
    int i = 0;
    for (; i < mod; i++)
      ans += input[i];

    for (; i < len; i++) {
      if ((i - mod) % K == 0 && (mod != 0 || i > mod))
        ans += '-';
      ans += input[i];
    }
    return ans;
  }
};
int main() {
  string S = "2-5g-3-j";
  int K = 2;
  Solution solution;
  cout << solution.licenseKeyFormatting(S, K);
  return 0;
}
