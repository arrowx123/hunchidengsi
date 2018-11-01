#include <algorithm>
#include <iostream>
#include <map>
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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Robot {
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};
class Solution {
private:
  long string_to_long(string s) {
    int len = s.size();
    long ans = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '.' || i == len - 1) {
        if (i != len - 1)
          end = i - 1;
        else
          end = i;
        string tmp = s.substr(start, end + 1 - start);
        ans = ans * 256 + stoi(tmp);
        start = i + 1;
      }
    }
    return ans;
  }
  int get_last_digit(long n) {
    int d = 0;
    while (true) {
      if (n & 1)
        break;
      n = (n >> 1);
      d++;
    }
    return d;
  }
  int get_length(long n) {
    int d = 0;
    while (n) {
      d++;
      n = (n >> 1);
    }
    return d - 1;
  }
  string long_to_string(long n) {
    string ans = "";
    for (int i = 0; i < 4; i++) {
      int num = n % 256;
      if (i == 0)
        ans = to_string(num);
      else
        ans = to_string(num) + "." + ans;
      n = (n >> 8);
    }
    return ans;
  }

public:
  vector<string> ipToCIDR(string ip, int n) {
    vector<string> ans;
    long ip_long = string_to_long(ip);
    while (n) {
      int mask = max(32 - get_last_digit(ip_long), 32 - get_length(n));
      ans.push_back(long_to_string(ip_long) + "/" + to_string(mask));
      ip_long += (1 << (32 - mask));
      n -= (1 << (32 - mask));
    }
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << endl;
    return ans;
  }
};
int main() {
  string ip = "255.0.0.7";
  int n = 10;
  Solution solution;
  solution.ipToCIDR(ip, n);
  return 0;
}
