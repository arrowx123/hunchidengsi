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
class MyHashSet {
private:
  vector<bool> record;
  int size = 1000000;

public:
  /** Initialize your data structure here. */
  MyHashSet() { record.resize(size + 10); }

  void add(int key) { record[key] = true; }

  void remove(int key) { record[key] = false; }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return record[key]; }
};
int main() {
  Solution solution;
  return 0;
}
