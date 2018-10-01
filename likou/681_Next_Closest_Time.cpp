#include <algorithm>
#include <iostream>
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
public:
  string nextClosestTime(string time) {
    vector<int> digits(4);
    digits[0] = time[0] - '0';
    digits[1] = time[1] - '0';
    digits[2] = time[3] - '0';
    digits[3] = time[4] - '0';
    string ans = "";
    int min_diff = INT_MAX;

    int ct = (digits[0] * 10 + digits[1]) * 60 + digits[2] * 10 + digits[3];

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          for (int l = 0; l < 4; l++) {
            int h = digits[i] * 10 + digits[j];
            int m = digits[k] * 10 + digits[l];
            string tmp = "";
            tmp += (digits[i] + '0');
            tmp += (digits[j] + '0');
            tmp += ':';
            tmp += (digits[k] + '0');
            tmp += (digits[l] + '0');

            if (h <= 23 && m <= 59) {

              int diff = (h * 60 + m + 24 * 60 - ct) % (24 * 60);
              if (diff < min_diff && tmp != time) {
                ans = tmp;
                min_diff = diff;
              }
            }
          }
        }
      }
    }
    if (ans.compare("") == 0)
      return time;
    else
      return ans;
  }
};
int main() {
  string time = "23:59";
  Solution solution;
  cout << solution.nextClosestTime(time);
  return 0;
}
