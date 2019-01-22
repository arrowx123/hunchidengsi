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
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};
class Solution {
public:
  vector<int> sortedSquares(vector<int> &A) {
    int len = A.size();
    vector<int> ans;

    int index = -1;
    int min_ = INT_MAX;
    for (int i = 0; i < len; i++) {
      if (A[i] * A[i] < min_) {
        min_ = A[i] * A[i];
        index = i;
      }
    }
    ans.push_back(A[index] * A[index]);
    int l = index - 1;
    int r = index + 1;

    while (l >= 0 && r < len) {
      if (A[l] * A[l] > A[r] * A[r]) {
        ans.push_back(A[r] * A[r]);
        r++;
      } else {
        ans.push_back(A[l] * A[l]);
        l--;
      }
    }

    for (; l >= 0; l--) {
      ans.push_back(A[l] * A[l]);
    }
    for (; r < len; r++) {
      ans.push_back(A[r] * A[r]);
    }

    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << " ";
    return ans;
  }
};
int main() {
  Solution solution;

  vector<int> A = {-7, -3, 2, 3, 11};
  solution.sortedSquares(A);
  return 0;
}
