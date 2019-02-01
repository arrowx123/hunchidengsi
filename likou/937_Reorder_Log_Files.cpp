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
  bool cmp(vector<string> v1, vector<string> v2) {
    bool v1_num = (v1[1][0] >= '0' && v1[1][0] <= '9');
    bool v2_num = (v2[1][0] >= '0' && v2[1][0] <= '9');

    if (v1_num && !v2_num) {
      return true;
    }
    if ((!v1_num && v2_num) || (v1_num && v2_num)) {
      return false;
    }

    for (int i = 1; i < (int)min(v1.size(), v2.size()); i++) {
      if (v1[i].compare(v2[i]) < 0)
        return false;
      else if (v1[i].compare(v2[i]) > 0)
        return true;
    }

    if (v1.size() > v2.size())
      return true;
		else if(v1.size() < v2.size())
			return false;

    if (v1[0].compare(v2[0]) > 0)
      return true;

    return false;
  }

public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<vector<string>> logs_vector;
    int size = logs.size();

    for (int i = 0; i < size; i++) {
      vector<string> tmp;
      int len = logs[i].size();

      string s = "";
      for (int j = 0; j < len; j++) {
        if (logs[i][j] != ' ')
          s += logs[i][j];
        else {
          tmp.push_back(s);
          s = "";
        }
      }
      tmp.push_back(s);
      logs_vector.push_back(tmp);
    }

    for (int i = size; i >= 0; i--) {
      for (int j = 0; j < i - 1; j++) {
        if (cmp(logs_vector[j], logs_vector[j + 1])) {
          vector<string> tmp = logs_vector[j];

          logs_vector[j] = logs_vector[j + 1];
          logs_vector[j + 1] = tmp;
        }
      }
    }

    vector<string> ans;
    for (int i = 0; i < (int)logs_vector.size(); i++) {
      string tmp = "";
      for (int j = 0; j < (int)logs_vector[i].size(); j++) {

        tmp += logs_vector[i][j];
        if (j != (int)logs_vector[i].size() - 1)
          tmp += " ";
      }
      ans.push_back(tmp);
    }

    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << endl;

    return ans;
  }
};
int main() {
  Solution solution;

  vector<string> logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7",
                         "ab1 off key dog", "a8 act zoo"};
  solution.reorderLogFiles(logs);
  return 0;
}
