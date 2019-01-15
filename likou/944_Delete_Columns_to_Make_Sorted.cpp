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
  int minDeletionSize(vector<string> &A) {
    int len = A.size();
    int size = A[0].size();
    int ans = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 1; j < len; j++) {
        if (A[j][i] < A[j - 1][i]) {
          ans++;
          break;
        }
      }
    }

    return ans;
  }
};
int main() {
  vector<string> A = {"cba", "daf", "ghi"};
  Solution solution;
  cout << solution.minDeletionSize(A);
  return 0;
}
