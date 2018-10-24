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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int len = intervals.size();
    vector<Interval> ans;

    if (!len) {
      ans.push_back(newInterval);
      return ans;
    }

    if (newInterval.end < intervals[0].start) {
      intervals.insert(intervals.begin(), newInterval);
    } else {
      int i = 0;
      for (; i < len; i++) {
        if (newInterval.start <= intervals[i].end) {
          if (newInterval.end < intervals[i].start) {
						intervals.insert(intervals.begin() + i, newInterval);
          } else {
            intervals[i].start = min(intervals[i].start, newInterval.start);
            intervals[i].end = max(intervals[i].end, newInterval.end);
          }
          break;
        }
      }
      if (i == len) {
        intervals.push_back(newInterval);
      }
    }

    Interval curr;
    int new_len = intervals.size();
    for (int i = 0; i < new_len; i++) {
      if (!i)
        curr = intervals[i];
      else {
        if (intervals[i].start <= curr.end) {
          curr.end = max(intervals[i].end, curr.end);
        } else {
          ans.push_back(curr);
          curr = intervals[i];
        }
      }

      if (i == new_len - 1) {
        ans.push_back(curr);
      }
    }
    return ans;
  }
};
int main() {
  vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7),
                                Interval(8, 10), Interval(12, 16)};
  Interval newInterval = Interval(4, 8);
  Solution solution;
  solution.insert(intervals, newInterval);
  return 0;
}
