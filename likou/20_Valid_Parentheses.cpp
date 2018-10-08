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
class Solution {
private:
  stack<char> st;
  char opposite(char c) {
    if (c == ')')
      return '(';
    else if (c == ']')
      return '[';
    else
      return '{';
  }

public:
  bool isValid(string s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        st.push(s[i]);
      else {
        if (st.empty() || st.top() != opposite(s[i]))
          return false;
        else
          st.pop();
      }
    }
    return st.empty();
  }
};
int main() {
  string s = "()";
  Solution solution;
  cout << solution.isValid(s);
  return 0;
}
