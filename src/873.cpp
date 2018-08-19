#include <algorithm>
#include <iostream>
#include <set>
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
  int lenLongestFibSubseq(vector<int> &A) {
    int ans = 0;
    unordered_set<int> has;

    int len = A.size();
    for (int i = 0; i < len; i++) {
      has.insert(A[i]);
    }

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        int l = A[j];
        int r = A[i] + A[j];
        int tmp = 2;

        while (has.count(r)) {
          tmp++;
          r = l + r;
          l = r - l;
        }

        ans = max(ans, tmp);
      }
    }
    return (ans >= 3) ? ans : 0;
  }
};
int main() {
  vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};
  Solution solution = Solution();
  cout << solution.lenLongestFibSubseq(A);
  return 0;
}
