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
private:
  vector<int> convert_to_binary(int n) {
    vector<int> v;
    for (int i = 0; i < 8; i++) {
      v.push_back(n & 1);
      n = (n >> 1);
    }
    reverse(v.begin(), v.end());
    return v;
  }

public:
  bool validUtf8(vector<int> &data) {
    int len = data.size();
    vector<int> d;
    for (int i = 0; i < len; i++) {
      vector<int> tmp = convert_to_binary(data[i]);
      d.insert(d.end(), tmp.begin(), tmp.end());
    }

    for (int i = 0; i < len; i++) {
      if (d[i * 8] == 0)
        continue;
      else {
        int j = 0;
        for (; j < 4; j++) {
          if (d[i * 8 + j] != 1)
            break;
        }
        if (d[i * 8 + j] == 1)
          return false;
        int k = 1;
        for (; k < j; k++) {
          if (d[(i + k) * 8] != 1 || d[(i + k) * 8 + 1] != 0)
            return false;
        }
        if (k == 1)
          return false;
        i += j - 1;
      }
    }
    return true;
  }
};

int main() {
  //  vector<int> data = {197, 130, 1};
  vector<int> data = {145};
  Solution solution;
  cout << solution.validUtf8(data);
  return 0;
}
