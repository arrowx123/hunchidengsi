#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
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
  int evalRPN(vector<string> &tokens) {
    int len = tokens.size();
    stack<int> nums;

    for (int i = 0; i < len; i++) {
      if (tokens[i] == "+") {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        nums.push(b + a);
      } else if (tokens[i] == "-") {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        nums.push(b - a);
      } else if (tokens[i] == "*") {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        nums.push(b * a);
      } else if (tokens[i] == "/") {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        nums.push(b / a);
      } else {
        nums.push(stoi(tokens[i]));
      }
    }
    return nums.top();
  }
};
int main() {
  vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                           "/",  "*", "17", "+", "5", "+"};
  Solution solution;
  cout << solution.evalRPN(tokens);
  return 0;
}
