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
  int wordsTyping(vector<string> &sentence, int rows, int cols) {
    int len = sentence.size();
    string overall = "";

    for (int i = 0; i < len; i++) {
      overall += sentence[i];
      overall += " ";
    }

    int row_idx = 0;
    int length = 0;
    while (row_idx < rows) {
      length += cols;
      while (overall[length % overall.size()] != ' ') {
        length--;
        if (length < 0)
          break;
      }
      length++;
      row_idx++;
    }
    return length / overall.size();
  }
};

int main() {
  int rows = 10000;
  int cols = 1;
  vector<string> sentence = {"hello"};
  Solution solution;
  cout << solution.wordsTyping(sentence, rows, cols);
  return 0;
}
