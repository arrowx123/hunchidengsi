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
class MyHashMap {
private:
  vector<int> v;

public:
  /** Initialize your data structure here. */
  MyHashMap() {
    v.resize(1000000 + 10);
    for (int i = 0; i < (int)v.size(); i++)
      v[i] = -1;
  }

  /** value will always be non-negative. */
  void put(int key, int value) { v[key] = value; }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) { return v[key]; }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) { v[key] = -1; }
};
int main() {
  return 0;
}
