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
class RecentCounter {
private:
  vector<int> records;

public:
  RecentCounter() {}

  int ping(int t) {
    records.push_back(t);

    while (true) {
      if (*(records.begin()) < t - 3000)
        records.erase(records.begin());
      else
        break;
    }
    return records.size();
  }
};
int main() { return 0; }
