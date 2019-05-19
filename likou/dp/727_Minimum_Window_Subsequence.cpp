// 727_Minimum_Window_Subsequence
// dp
class Solution {
public:
  string minWindow(string S, string T) {
    int m = S.size();
    int n = T.size();

    int dp[n + 10][m + 10];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < m; i++) {
      if (S[i] == T[0])
        dp[0][i] = i;
    }

    for (int i = 1; i < n; i++) {
      int k = -1;
      for (int j = 0; j < m; j++) {
        if (T[i] == S[j] && k != -1)
          dp[i][j] = k;
        if (dp[i - 1][j] != -1)
          k = dp[i - 1][j];
      }
    }

    int idx = -1;
    int len = INT_MAX;
    for (int i = 0; i < m; i++) {
      int clen = i - dp[n - 1][i] + 1;
      if (dp[n - 1][i] != -1 && clen < len) {
        len = clen;
        idx = dp[n - 1][i];
      }
    }

    return idx == -1 ? "" : S.substr(idx, len);
  }
};
