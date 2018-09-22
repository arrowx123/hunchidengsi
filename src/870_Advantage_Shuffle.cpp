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
  vector<int> advantageCount(vector<int> &A, vector<int> &B) {
    int len = A.size();
    vector<int> sortedB = B;
    unordered_map<int, stack<int>> umap;
    stack<int> r;
    vector<int> ans;

    sort(A.begin(), A.end());
    sort(sortedB.begin(), sortedB.end());

    int idx = 0;
    for (int i = 0; i < len; i++) {
      if (A[i] > sortedB[idx]) {
        umap[sortedB[idx++]].push(A[i]);
      } else {
        r.push(A[i]);
      }
    }
    for (int i = 0; i < len; i++) {
      if (umap[B[i]].size()) {
        ans.push_back(umap[B[i]].top());
        umap[B[i]].pop();
      } else {
        ans.push_back(r.top());
        r.pop();
      }
    }
    cout << endl;
    for (int i = 0; i < len; i++)
      cout << ans[i] << " ";
    return ans;
  }
};
int main() {
  vector<int> A = {8, 2, 4, 4, 5, 6, 6, 0, 4, 7};
  vector<int> B = {0, 8, 7, 4, 4, 2, 8, 5, 2, 0};
  Solution solution;
  solution.advantageCount(A, B);
  return 0;
}
