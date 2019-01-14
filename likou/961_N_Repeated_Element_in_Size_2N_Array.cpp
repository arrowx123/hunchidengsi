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
  int repeatedNTimes(vector<int> &A) {
    int len = A.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < len; i++) {
      umap[A[i]]++;
    }
    int ans = A[0];
    for (auto ele : umap) {
      if (ele.second != 1) {
        ans = ele.first;
      }
    }
    return ans;
  }
};
int main() {
  vector<int> A = {5, 1, 5, 2, 5, 3, 5, 4};
  Solution solution;
  cout << solution.repeatedNTimes(A);
  return 0;
}
