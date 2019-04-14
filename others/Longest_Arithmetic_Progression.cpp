#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int solve(vector<int> &v) {

  int ans = 0;
  int len = v.size();
  vector<vector<int>> dp(len, vector<int>(len));

  for (int i = len - 1; i >= 0; i--) {
    int cur_len = 1;
    for (int j = i + 1; j < len; j++) {
      int diff = v[i] - v[j];
      cur_len = 2;
      for (int k = j + 1; k < len; k++) {
        if (v[j] - v[k] == diff) {
          cur_len = max(cur_len, dp[j][k] + 1);
        }
      }
      dp[i][j] = cur_len;
      ans = max(ans, cur_len);
    }
  }
  return ans;
}
int main() {
  vector<int> input = {1, 7, 10, 15, 27, 29};
  return solve(input);
}
