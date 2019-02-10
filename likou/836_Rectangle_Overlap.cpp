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
  bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
    bool x = ((rec2[0] >= rec1[0] && rec2[0] < rec1[2]) ||
              (rec2[2] > rec1[0] && rec2[2] <= rec1[2]) ||
              (rec2[0] <= rec1[0] && rec2[2] >= rec1[2]) ||
              (rec1[0] <= rec2[0] && rec1[2] >= rec2[2]));
    bool y = ((rec2[1] >= rec1[1] && rec2[1] < rec1[3]) ||
              (rec2[3] > rec1[1] && rec2[3] <= rec1[3]) ||
              (rec2[1] <= rec1[1] && rec2[3] >= rec1[3]) ||
              (rec1[1] <= rec2[1] && rec1[3] >= rec2[3]));
    return x && y;
  };
};
int main() {
  Solution solution;

  vector<int> rec1 = {0, 0, 2, 2};
  vector<int> rec2 = {1, 1, 3, 3};
  solution.isRectangleOverlap(rec1, rec2);
  return 0;
}
