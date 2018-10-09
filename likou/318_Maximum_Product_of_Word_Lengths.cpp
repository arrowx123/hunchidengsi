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
public:
  int maxProduct(vector<string> &words) {
    int len = words.size();
    vector<int> bit(len);
    int ans = 0;

    for (int i = 0; i < len; i++) {
      for (int j = 0; j < (int)words[i].size(); j++) {
        bit[i] |= (1 << (words[i][j] - 'a'));
      }
    }

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if ((bit[i] & bit[j]) == 0) {
          ans = max(ans, (int)(words[i].size() * words[j].size()));
        }
      }
    }
    return ans;
  }
};
int main() {
  vector<string> words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  Solution solution;
  cout << solution.maxProduct(words);
  return 0;
}
