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
private:
  vector<int> used;
  bool same(string a, string b) {
    vector<int> record;
    vector<int> ao(128);
    vector<int> bo(128);
    vector<int> ae(128);
    vector<int> be(128);

    if (a.size() != b.size())
      return false;

    for (int i = 0; i < (int)a.size(); i++) {
      if (i % 2 == 0) {
        ae[a[i]]++;
        be[b[i]]++;

      } else {
        ao[a[i]]++;
        bo[b[i]]++;
      }
    }

    for (int i = 0; i < (int)ae.size(); i++) {
      if (ae[i] != be[i])
        return false;
    }
    for (int i = 0; i < (int)ao.size(); i++) {
      if (ao[i] != bo[i])
        return false;
    }
    return true;
  }

public:
  int numSpecialEquivGroups(vector<string> &A) {
    int ans = 0;
    int n = A.size();
    used.resize(n);

    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;
      used[i] = i + 1;
      for (int j = i + 1; j < n; j++) {
        if (same(A[i], A[j])) {
          used[j] = i + 1;
        }
      }
      ans++;
    }
    for (int i = 0; i < (int)used.size(); i++) {
      cout << used[i] << " ";
    }
    cout << endl;
    return ans;
  }
};
int main() {
  vector<string> A = {"abcd", "cdab", "adcb", "cbad"};
  Solution solution = Solution();
  cout << solution.numSpecialEquivGroups(A);
  return 0;
}
