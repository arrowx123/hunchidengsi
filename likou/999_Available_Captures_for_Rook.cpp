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
  int numRookCaptures(vector<vector<char>> &board) {
    int N = 8;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == 'R') {

          int k = i + 1;
          while (k < N) {
            if (board[k][j] >= 'A' && board[k][j] <= 'Z')
              break;
            else if (board[k][j] >= 'a' && board[k][j] <= 'z') {
              ans++;
              break;
            }
            k++;
          }
          k = i - 1;
          while (k >= 0) {
            if (board[k][j] >= 'A' && board[k][j] <= 'Z')
              break;
            else if (board[k][j] >= 'a' && board[k][j] <= 'z') {
              ans++;
              break;
            }
            k--;
          }
          int l = j + 1;
          while (l < N) {
            if (board[i][l] >= 'A' && board[i][l] <= 'Z')
              break;
            else if (board[i][l] >= 'a' && board[i][l] <= 'z') {
              ans++;
              break;
            }
            l++;
          }
          l = j - 1;
          while (l >= 0) {
            if (board[i][l] >= 'A' && board[i][l] <= 'Z')
              break;
            else if (board[i][l] >= 'a' && board[i][l] <= 'z') {
              ans++;
              break;
            }
            l--;
          }
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;

  return 0;
}
