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
  int fib(int N) {
		if(!N)
			return 0;

    int l = 0;
    int r = 1;
    for (int i = 2; i <= N; i++) {
      int new_ = l + r;
      l = r;
      r = new_;
    }

    return r;
  }
};
int main() {
  Solution solution;

  int N = 3;
  solution.fib(N);
  return 0;
}
