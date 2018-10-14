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
  class Trie {
  public:
    vector<int> prefix;
    Trie *children[26];
    Trie() { memset(children, 0, sizeof(children)); }
  };
  Trie *build(vector<string> &words) {
    int len = words.size();
    Trie *root = new Trie();
    for (int i = 0; i < len; i++) {
      Trie *p = root;
      for (int j = 0; j < (int)words[i].size(); j++) {
        if (p->children[words[i][j] - 'a'] == NULL)
          p->children[words[i][j] - 'a'] = new Trie();
        p = p->children[words[i][j] - 'a'];
        p->prefix.push_back(i);
      }
    }
    return root;
  }
  void helper(vector<vector<string>> &ans, vector<string> &words,
              vector<string> &board, int row, Trie *root) {
    if (row == (int)board[0].size()) {
      ans.push_back(board);
      return;
    }
    Trie *p = root;
    for (int i = 0; i < row; i++) {
      if (p->children[board[i][row] - 'a'] == NULL)
        return;
      p = p->children[board[i][row] - 'a'];
    }
    for (auto ele : p->prefix) {
      board[row] = words[ele];
      helper(ans, words, board, row + 1, root);
    }
  }

public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    int len = words.size();
    Trie *root = build(words);
    vector<string> board(words[0].size());
    vector<vector<string>> ans;
    for (int i = 0; i < len; i++) {
      board[0] = words[i];
      helper(ans, words, board, 1, root);
    }

    return ans;
  }
};
int main() {
  vector<string> words = {"abat", "baba", "atan", "atal"};
  Solution solution;
  solution.wordSquares(words);
  return 0;
}
