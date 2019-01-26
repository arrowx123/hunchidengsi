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
  int smallestRangeI(vector<int> &A, int K) {
    int min_ = INT_MAX;
    int max_ = INT_MIN;
    int size = A.size();

    for (int i = 0; i < size; i++) {
      if (min_ > A[i])
        min_ = A[i];
      if (max_ < A[i])
        max_ = A[i];
    }

    int ans = max_ - 2 * K - min_;
    if (ans < 0)
      return 0;
    return ans;
  }
};
int main() {
  Solution solution;

  vector<int> A = {1, 3, 6};
  int K = 3;
  cout << solution.smallestRangeI(A, K);
  return 0;
}
