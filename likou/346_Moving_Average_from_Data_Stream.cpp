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
class MovingAverage {
private:
  vector<int> d;
  int idx = 0;
  int size;

public:
  /** Initialize your data structure here. */
  MovingAverage(int size) { this->size = size; }

  double next(int val) {
    if ((int)d.size() < size)
      d.push_back(val);
    else {
      d[idx] = val;
      idx = (idx + 1) % size;
    }
    int len = d.size();
    double ans = 0;
    for (int i = 0; i < len; i++)
      ans += d[i];
    return ans / len;
  }
};

int main() { return 0; }
