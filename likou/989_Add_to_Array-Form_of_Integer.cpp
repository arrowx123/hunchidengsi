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
  vector<int> addToArrayForm(vector<int> &A, int K) {
    vector<int> B;
    vector<int> ans;
    while (K) {
      B.push_back(K % 10);
      K /= 10;
    }

    reverse(A.begin(), A.end());

    int c = 0;
    int i = 0;
    for (; i < (int)min(A.size(), B.size()); i++) {
      int sum = A[i] + B[i] + c;
      ans.push_back(sum % 10);
      c = sum / 10;
    }

    for (; i < (int)A.size(); i++) {
      int sum = A[i] + c;
      ans.push_back(sum % 10);
      c = sum / 10;
    }
    for (; i < (int)B.size(); i++) {
      int sum = B[i] + c;
      ans.push_back(sum % 10);
      c = sum / 10;
    }

    if (c)
      ans.push_back(c);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
int main() {
  Solution solution;

  vector<int> A = {1, 2, 0, 0};
  int K = 34;
  solution.addToArrayForm(A, K);
  return 0;
}
