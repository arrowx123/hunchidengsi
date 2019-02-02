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
  string reverseOnlyLetters(string S) {
    int size = S.size();

    int i = 0;
    int j = size - 1;

    while (i <= j) {
      if (!isalpha(S[i])) {
        i++;
        continue;
      }
      if (!isalpha(S[j])) {
        j--;
        continue;
      }

      char tmp = S[i];
      S[i] = S[j];
      S[j] = tmp;
      i++;
      j--;
    }
    return S;
  }
};
int main() {
  Solution solution;

  string S = "a-bC-dEf-ghIj";
  solution.reverseOnlyLetters(S);
  return 0;
}
