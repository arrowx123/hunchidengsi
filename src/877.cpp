#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    int len = piles.size();
    vector<vector<int>> dp(len, vector<int>(len));
    for (int i = 0; i < len; i++) {
      dp[i][i] = -piles[i];
    }
    for (int l = 1; l < len; l++) {
      for (int i = 0, j = i + l; j < len; i++, j++) {
        if ((j - i + 1) % 2 == 0)
          dp[i][j] = max(piles[i] + dp[i + 1][j], piles[j] + dp[i][j - 1]);
        else
          dp[i][j] = min(-piles[i] + dp[i + 1][j], -piles[j] + dp[i][j - 1]);
      }
    }

    if (dp[0][len - 1] > 0)
      return true;
    return false;
  }
};

int main() {

  vector<int> piles = {5, 3, 4, 5};
  Solution solution = Solution();
  solution.stoneGame(piles);

  return 0;
}
