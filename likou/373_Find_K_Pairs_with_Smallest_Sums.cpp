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
  vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                        int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<pair<int, int>> ans;
    if (!len1 || !len2)
      return ans;

    auto cmp = [&, nums1, nums2](pair<int, int> p1, pair<int, int> p2) mutable {
      return nums1[p1.first] + nums2[p1.second] >
             nums1[p2.first] + nums2[p2.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    for (int i = 0; i < len1 && i < k; i++) {
      pq.push({i, 0});
    }

    while (k-- && pq.size()) {
      pair<int, int> p = pq.top();
      pq.pop();
      ans.push_back({nums1[p.first], nums2[p.second]});
      if (p.second + 1 == len2)
        continue;
      pq.push({p.first, p.second + 1});
    }

    return ans;
  }
};
int main() {
  vector<int> nums1 = {1, 1, 2};
  vector<int> nums2 = {1, 2, 3};
  int k = 10;
  Solution solution;
  solution.kSmallestPairs(nums1, nums2, k);
  return 0;
}
