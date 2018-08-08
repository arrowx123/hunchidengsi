#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  void copy(vector<vector<int>> &s, vector<vector<int>> &d) {
    for (int i = 0; i < (int)s.size(); i++) {
      for (int j = 0; j < (int)s[i].size(); j++) {
        d[i][j] = s[i][j];
      }
    }
  }

public:
  int profitableSchemes(int G, int P, vector<int> &group, vector<int> &profit) {
    int len = group.size();
    int mod = 1e9 + 7;
    int ans = 0;
    vector<vector<int>> sum(P + 1, vector<int>(G + 1));
    sum[0][0] = 1;

    for (int i = 0; i < len; i++) {
      int g = group[i];
      int p = profit[i];

      vector<vector<int>> tmp(P + 1, vector<int>(G + 1));
      copy(sum, tmp);
      for (int j = 0; j <= G - g; j++) {
        for (int k = 0; k <= P; k++) {
          int np = min(p + k, P);
          tmp[np][j + g] = (tmp[np][j + g] + sum[k][j]) % mod;
        }
      }
      copy(tmp, sum);
    }

    for (int i = 0; i < (int)sum[P].size(); i++) {
      ans = (ans + sum[P][i]) % mod;
    }
    return ans;
  }
};
int main() {
  int G = 10;
  int P = 5;
  vector<int> group = {2, 3, 5};
  vector<int> profit = {6, 7, 8};
  Solution solution = Solution();
  cout << solution.profitableSchemes(G, P, group, profit);

  return 0;
}
