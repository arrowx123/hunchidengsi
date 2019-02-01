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
  string toGoatLatin(string S) {
    int size = S.size();
    vector<string> words;
    vector<string> ans;

    string tmp = "";
    for (int i = 0; i < size; i++) {
      if (S[i] == ' ') {
        words.push_back(tmp);
        tmp = "";
      } else {
        tmp += S[i];
      }
    }
    words.push_back(tmp);

    for (int i = 0; i < (int)words.size(); i++) {
      string tmp = "";
      string appendix = "";
      for (int j = 0; j < (int)words[i].size(); j++) {
        if (j == 0) {
          if (words[i][j] == 'a' || words[i][j] == 'e' || words[i][j] == 'i' ||
              words[i][j] == 'o' || words[i][j] == 'u' || words[i][j] == 'A' ||
              words[i][j] == 'E' || words[i][j] == 'I' || words[i][j] == 'O' ||
              words[i][j] == 'U') {
            tmp += words[i][j];
          } else {
            appendix += words[i][j];
          }
          appendix += "ma";
        } else {
          tmp += words[i][j];
        }
      }
      for (int k = 0; k <= i; k++)
        appendix += "a";
      ans.push_back(tmp + appendix);
    }

    string result = "";
    for (int i = 0; i < (int)ans.size(); i++) {
      result += ans[i];
      if (i != (int)ans.size() - 1)
        result += " ";
    }
    return result;
  }
};
int main() {
  Solution solution;

  string S = "I speak Goat Latin";
  cout << solution.toGoatLatin(S);
  return 0;
}
