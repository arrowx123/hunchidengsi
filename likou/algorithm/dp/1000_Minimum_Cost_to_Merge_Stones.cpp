// 1000_Minimum_Cost_to_Merge_Stones
// O(kn^3)
// dp bottom up
const int MAX = 1e9;
const int SIZE = 31;

class Solution {
public:
  int mergeStones(vector<int> &stones, int K) {
    int n = stones.size();

    int dp[SIZE][SIZE][SIZE];
    int prev[SIZE];
    for (int i = 1; i <= n; i++)
      prev[i] = prev[i - 1] + stones[i - 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k <= K; k++)
          dp[i][j][k] = MAX;
      }
      dp[i][i][1] = 0;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        for (int t = i; t < j; t++) {
          for (int g = 2; g <= K; g++) {
            dp[i][j][g] = min(dp[i][j][g], dp[i][t][g - 1] + dp[t + 1][j][1]);
          }
          dp[i][j][1] = dp[i][j][K] + prev[j + 1] - prev[i];
        }
      }
    }

    return dp[0][n - 1][1] >= MAX ? -1 : dp[0][n - 1][1];
  }
};
