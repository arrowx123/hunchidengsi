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
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int len = s.size();
    int l = 0;
    int r = 0;
    int ans = 0;
    unordered_map<char, int> umap;

    while (true) {
      if (r == len)
        break;
      umap[s[r]]++;
      if ((int)umap.size() <= k)
        ans = max(ans, r - l + 1);
      else {
        while ((int)umap.size() > k) {
          umap[s[l]]--;
          if (!umap[s[l]]) {
            umap.erase(s[l]);
          }
          l++;
        }
      }
      r++;
    }

    return ans;
  }
};
int main() {
  string s = "aa";
  int k = 1;
  Solution solution;
  cout << solution.lengthOfLongestSubstringKDistinct(s, k);
  return 0;
}
