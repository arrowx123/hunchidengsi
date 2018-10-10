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
  unordered_set<string> uset;
  vector<int> record;

  bool check(string &s, int idx) {
    if (idx == s.size())
      return true;

    if (record[idx] != -1)
      return record[idx];

    string tmp = "";
    for (int i = idx; i < s.size(); i++) {
      tmp += s[i];
      if (uset.count(tmp)) {
        if (check(s, i + 1))
          return record[idx] = true;
      }
    }
    return record[idx] = false;
  }

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    record.resize(s.size());
    for (int i = 0; i < s.size(); i++)
      record[i] = -1;
    for (int i = 0; i < wordDict.size(); i++) {
      uset.insert(wordDict[i]);
    }
    return check(s, 0);
  }
};
int main() {
  string s = "applepenapple";
  vector<string> wordDict = {"apple", "pen", "cats", "dog",
                             "sand",  "and", "cat"};
  Solution solution;
  cout << solution.wordBreak(s, wordDict);
  return 0;
}
