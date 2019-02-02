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
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {}

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};
class Solution {
private:
  Node *recursion(int r, int c, int len, vector<vector<int>> &grid) {
    int v = grid[r][c];
    bool same = true;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if (grid[r + i][c + j] != v)
          same = false;
      }
    }

    if (same)
      return new Node(v, true, NULL, NULL, NULL, NULL);
    else {
      return new Node(v, false, recursion(r, c, len / 2, grid),
                      recursion(r, c + len / 2, len / 2, grid),
                      recursion(r + len / 2, c, len / 2, grid),
                      recursion(r + len / 2, c + len / 2, len / 2, grid));
    }
  }

public:
  Node *construct(vector<vector<int>> &grid) {
    return recursion(0, 0, grid.size(), grid);
  }
};
int main() {
  Solution solution;
  return 0;
}
