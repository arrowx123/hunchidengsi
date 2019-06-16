// 1092_Shortest_Common_Supersequence
// dp
class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        if (str1[i] == str2[j])
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }

    string common = "";
    int i = m;
    int j = n;

    while (i && j) {
      if (str1[i - 1] == str2[j - 1]) {
        common += str1[i - 1];
        i--;
        j--;
      } else if (dp[i][j] == dp[i - 1][j]) {
        i--;
      } else if (dp[i][j] == dp[i][j - 1]) {
        j--;
      }
    }

    reverse(common.begin(), common.end());
    vector<bool> p1(m);
    vector<bool> p2(n);

    for (int i = 0, idx = 0; i < m; i++) {
      if (idx < common.size() && str1[i] == common[idx]) {
        p1[i] = true;
        idx++;
      }
    }

    for (int i = 0, idx = 0; i < n; i++) {
      if (idx < common.size() && str2[i] == common[idx]) {
        p2[i] = true;
        idx++;
      }
    }

    i = j = 0;
    string ans = "";
    while (i < m || j < n) {
      if (i < m && !p1[i])
        ans += str1[i++];
      else if (j < n && !p2[j])
        ans += str2[j++];
      else {
        ans += str1[i];
        i++;
        j++;
      }
    }

    return ans;
  }
};
