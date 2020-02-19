// 1140_Stone_Game_II
// dp recursion
class Solution {
private:
  vector<int> sum;
  vector<int> piles;
  vector<vector<int>> dp;

  int find(int x, int m) {
    if (x + 2 * m - 1 >= piles.size() - 1)
      return sum.back() - sum[x];
    if (dp[x][m] != -1)
      return dp[x][m];
    int rest = INT_MAX;
    for (int i = 0; i < 2 * m; i++) {
      int cur = find(x + i + 1, max(i + 1, m));
      rest = min(rest, cur);
    }
    return dp[x][m] = sum.back() - sum[x] - rest;
  }

public:
  int stoneGameII(vector<int> &piles) {
    int n = piles.size();
    dp.resize(n, vector<int>(n));
    for (auto &v : dp)
      fill(v.begin(), v.end(), -1);

    this->piles = piles;
    sum.resize(n + 1);
    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + piles[i];
    return find(0, 1);
  }
};

// dp iteration
int dp[110][220];
int sum[110];

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    int n = piles.size();

    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + piles[i];

    for (int i = n - 1; i >= 0; i--) {
      for (int m = 1; m <= 2 * n; m++) {
        int max_ = INT_MIN;
        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
          max_ = max(max_, sum[n] - sum[i] - dp[i + x][max(x, m)]);
        }
        dp[i][m] = max_;
      }
    }
    return dp[0][1];
  }
};
