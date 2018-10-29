#include <algorithm>
#include <iostream>
#include <map>
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
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Robot {
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};
class Solution {
private:
  vector<int> offset = {-1, 0, 1, 0, -1};
  vector<string> ans;
  class Node {
  public:
    bool is_word;
    Node *next[26];
  };
  void build_trie(string s, Node *node) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
      if (node->next[s[i] - 'a'] == NULL) {
        node->next[s[i] - 'a'] = new Node();
      }
      node = node->next[s[i] - 'a'];
    }
    node->is_word = true;
  }
  void traverse(int x, int y, vector<vector<char>> &board, string s, Node *node,
                vector<vector<bool>> visited) {
    visited[x][y] = true;
    if (node->is_word) {
      ans.push_back(s);
      node->is_word = false;
    }
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < 4; i++) {
      int nx = x + offset[i];
      int ny = y + offset[i + 1];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == false) {
        if (node->next[board[nx][ny] - 'a']) {
          traverse(nx, ny, board, s + board[nx][ny],
                   node->next[board[nx][ny] - 'a'], visited);
        }
      }
    }
    return;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int m = board.size();
    if (!m)
      return ans;
    int n = board[0].size();

    int len = words.size();
    Node *root = new Node();

    for (int i = 0; i < len; i++) {
      build_trie(words[i], root);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (root->next[board[i][j] - 'a']) {
          vector<vector<bool>> visited(m, vector<bool>(n));
          string s;
          s += board[i][j];
          traverse(i, j, board, s, root->next[board[i][j] - 'a'], visited);
        }
      }
    }
    auto cmp = [](string a, string b) { return a.compare(b) < 0; };
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << endl;
    return ans;
  }
};
int main() {
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
  Solution solution;
  solution.findWords(board, words);
  return 0;
}
