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
  int sumSubarrayMins(vector<int> &A) {
    int len = A.size();
    int mod = 1000000007;
    long ans = 0;
    vector<int> prev(len);
    vector<int> next(len);

    stack<int> s;
    for (int i = 0; i < len; i++) {
      while (s.empty() == false && A[i] <= A[s.top()])
        s.pop();
      prev[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }

    s = stack<int>();
    for (int i = len - 1; i >= 0; i--) {
      while (s.empty() == false && A[i] < A[s.top()])
        s.pop();
      next[i] = s.empty() ? len : s.top();
      s.push(i);
    }

    for (int i = 0; i < len; i++) {
      cout << prev[i] << " " << next[i] << endl;
    }

    for (int i = 0; i < len; i++) {
      ans = ((i - prev[i]) * (next[i] - i) % mod * A[i] % mod + ans) % mod;
    }

    return ans;
  }
};
int main() {
  vector<int> A = {3, 1, 2, 4};
  Solution solution;
  cout << solution.sumSubarrayMins(A);
  return 0;
}
