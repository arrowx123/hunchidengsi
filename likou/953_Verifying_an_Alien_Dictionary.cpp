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
  bool isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> umap;
    for (int i = 0; i < (int)order.size(); i++) {
      umap[order[i]] = i;
    }

    for (int i = 0; i < (int)words.size() - 1; i++) {
      string w1 = words[i];
      string w2 = words[i + 1];

      int j = 0;
      for (; j < (int)min(w1.size(), w2.size()); j++) {
        if (umap[w1[j]] > umap[w2[i]])
          return false;
        else if (umap[w1[j]] < umap[w2[j]])
          break;
      }
      if (j == (int)min(w1.size(), w2.size()) && w1.size() > w2.size())
        return false;
    }
    return true;
  }
};
int main() {
  Solution solution;

  vector<string> words = {"hello", "leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  cout << solution.isAlienSorted(words, order);
  return 0;
}
