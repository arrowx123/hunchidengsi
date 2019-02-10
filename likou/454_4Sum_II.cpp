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
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    int len = A.size();
    int ans = 0;
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;

    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        map1[A[i] + B[j]]++;
        map2[C[i] + D[j]]++;
      }
    }

    for (auto ele : map1) {
      ans += ele.second * map2[-ele.first];
    }
    return ans;
  }
};
int main() {
  Solution solution;

  vector<int> A = {1, 2};
  vector<int> B = {-2, -1};
  vector<int> C = {-1, 2};
  vector<int> D = {0, 2};
  cout << solution.fourSumCount(A, B, C, D);
  return 0;
}
