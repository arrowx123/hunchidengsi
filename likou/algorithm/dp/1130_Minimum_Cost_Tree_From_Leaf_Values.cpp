// 1130_Minimum_Cost_Tree_From_Leaf_Values
// dp
class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> best(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      dp[i][i] = best[i][i] = arr[i];

    for (int k = 1; k < n; k++) {
      for (int i = 0; i + k < n; i++)
        best[i][i + k] = max(best[i][i + k - 1], best[i + k][i + k]);
    }

    for (int k = 1; k < n; k++) {
      for (int i = 0; i + k < n; i++) {
        int j = i + k;
        dp[i][j] = INT_MAX;
        for (int m = i + 1; m <= j; m++) {
          dp[i][j] = min(dp[i][j],
                         best[i][m - 1] * best[m][j] + dp[i][m - 1] + dp[m][j]);
        }
      }
    }

    int ret = dp[0][n - 1];
    for (auto val : arr)
      ret -= val;
    return ret;
  }
};
