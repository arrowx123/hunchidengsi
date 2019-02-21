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
  int maxDistToClosest(vector<int> &seats) {
    int l = 0;
    int r = 0;
    int ans = 0;

    while (l < (int)seats.size()) {
      if (seats[l] == 0) {
        r = l;
        for (; r < (int)seats.size(); r++) {
          if (seats[r] != 0)
            break;
        }
        r--;
        if (l == 0 || r == (int)seats.size() - 1) {
          ans = max(ans, r - l);
        } else {
          ans = max(ans, (r - l) / 2);
        }
        l = r + 1;
      } else {
        l++;
      }
    }
    return ans + 1;
  }
};
int main() {
  Solution solution;

  vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
  cout << solution.maxDistToClosest(seats);
  return 0;
}
