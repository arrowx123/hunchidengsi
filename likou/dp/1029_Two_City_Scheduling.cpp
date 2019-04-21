// 1029_Two_City_Scheduling
// dp
const int MAX = 1e9;
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    int n = costs.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < n + 1; j++)
        dp[i][j] = MAX;
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + costs[i - 1][0]);
        if (j > 0)
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + costs[i - 1][1]);
      }
    }
    return dp[n][n / 2];
  }
};
