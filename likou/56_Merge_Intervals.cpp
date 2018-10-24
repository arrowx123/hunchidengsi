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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    int len = intervals.size();
    vector<Interval> ans;
    if (!len)
      return ans;

    auto cmp = [](Interval int1, Interval int2) {
      if (int1.start != int2.start)
        return int1.start < int2.start;
      return int1.end < int2.end;
    };
    sort(intervals.begin(), intervals.end(), cmp);
    Interval curr;
    for (int i = 0; i < len; i++) {
      if (!i)
        curr = intervals[0];
      else {
        if (intervals[i].start <= curr.end) {
          curr.end = max(curr.end, intervals[i].end);
        } else {
          ans.push_back(curr);
          curr = intervals[i];
        }
      }

      if (i == len - 1) {
        ans.push_back(curr);
      }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i].start << " " << ans[i].end << endl;
    }
    return ans;
  }
};
int main() {
  vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10),
                                Interval(15, 18)};
  Solution solution;
  solution.merge(intervals);
  return 0;
}
