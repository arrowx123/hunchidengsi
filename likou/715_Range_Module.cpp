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
class RangeModule {
private:
  vector<pair<int, int>> range;

public:
  RangeModule() {}

  void addRange(int left, int right) {
    int len = range.size();
    vector<pair<int, int>> tmp;
    for (int i = 0; i < len; i++) {
      if (right < range[i].first) {
        tmp.push_back({left, right});
        while (i < len) {
          tmp.push_back(range[i++]);
          left = right = -1;
        }
      } else if (left <= range[i].second) {
        left = min(range[i].first, left);
        right = max(range[i].second, right);
      } else {
        tmp.push_back(range[i]);
      }
    }
    if (left != -1)
      tmp.push_back({left, right});
    range = tmp;
    return;
  }

  bool queryRange(int left, int right) {
    int len = range.size();
    if (!len)
      return false;

    int l = 0;
    int r = len - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (right <= range[mid].first) {
        r = mid;
      } else if (left >= range[mid].second) {
        l = mid + 1;
      } else {
        l = r = mid;
      }
    }
    return left >= range[l].first && right <= range[l].second;
  }

  void removeRange(int left, int right) {
    int len = range.size();
    vector<pair<int, int>> tmp;
    for (int i = 0; i < len; i++) {
      if (right <= range[i].first) {
        while (i < len) {
          tmp.push_back(range[i++]);
        }
      } else if (left >= range[i].second) {
        tmp.push_back(range[i]);
      } else {
        int l = range[i].first;
        int r = range[i].second;
        if (left > l) {
          tmp.push_back({l, left});
        }
        if (right < r) {
          tmp.push_back({right, r});
        }
      }
    }
    range = tmp;
    return;
  }
};
int main() {
  RangeModule rangeModule;
  rangeModule.addRange(5, 8);
  rangeModule.queryRange(3, 4);
  rangeModule.removeRange(5, 6);
  rangeModule.removeRange(3, 6);
  rangeModule.addRange(1, 3);
  rangeModule.queryRange(2, 3);

  return 0;
}
