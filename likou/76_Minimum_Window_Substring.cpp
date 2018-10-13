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
  unordered_map<char, int> tmap;
  unordered_map<char, int> smap;

public:
  string minWindow(string s, string t) {
    int len_s = s.size();
    int len_t = t.size();
    for (int i = 0; i < len_t; i++)
      tmap[t[i]]++;

    int l = 0;
    int r = 0;
    int condition = 0;

    int lmin = -1;
    int rmin = -1;

    while (r < len_s) {
      smap[s[r]]++;
      if (tmap.count(s[r]) && smap[s[r]] == tmap[s[r]])
        condition++;
      r++;

      if (condition == (int)tmap.size()) {
        while (condition == (int)tmap.size()) {
          if (lmin == -1 || r - l < rmin - lmin) {
            lmin = l;
            rmin = r;
          }
          smap[s[l]]--;
          if (tmap.count(s[l]) && smap[s[l]] == tmap[s[l]] - 1)
            condition--;
          l++;
        }
      }
    }
    string ans = "";
    if (lmin != -1)
      ans = s.substr(lmin, rmin - lmin);
    return ans;
  }
};
int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  Solution solution;
  cout << solution.minWindow(s, t);
  return 0;
}
