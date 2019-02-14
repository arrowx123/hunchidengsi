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
class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k = 0;

public:
  KthLargest(int k, vector<int> nums) {
    this->k = k;
    for (int i = 0; i < (int)nums.size(); i++) {
      pq.push(nums[i]);
      if ((int)pq.size() > k) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    pq.push(val);
    if ((int)pq.size() > k)
      pq.pop();
    return pq.top();
  }
};
int main() { return 0; }
