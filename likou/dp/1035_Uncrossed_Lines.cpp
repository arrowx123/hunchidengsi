// 1035_Uncrossed_Lines
// dp
const int N = 500 + 10;
class Solution {
public:
  int maxUncrossedLines(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int dp[N][N];
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = 0;
        if (!i || !j)
          continue;

        if (A[i - 1] == B[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
    }
    return dp[m][n];
  }
};
