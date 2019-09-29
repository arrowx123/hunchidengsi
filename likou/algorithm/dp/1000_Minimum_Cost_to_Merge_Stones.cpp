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
        for (int g = 2; g <= K; g++) {
          for (int t = i; t < j; t++) {
            dp[i][j][g] = min(dp[i][j][g], dp[i][t][g - 1] + dp[t + 1][j][1]);
          }
        }
        dp[i][j][1] = dp[i][j][K] + prev[j + 1] - prev[i];
      }
    }

    return dp[0][n - 1][1] >= MAX ? -1 : dp[0][n - 1][1];
  }
};

// O(kn^3)
// dp top down
const int SIZE = 31;
const int MAX = 1e9;

class Solution {
private:
  vector<int> stones;
  vector<int> prev;
  int mem[SIZE][SIZE][SIZE];

  int n;
  int K;

  int dp(int l, int r, int g) {
    if (mem[l][r][g] != -1)
      return mem[l][r][g];
    int &ret = mem[l][r][g];
    ret = MAX;

    if (l == r)
      return ret;
    if (g == 1)
      return mem[l][r][g] = dp(l, r, K) + prev[r + 1] - prev[l];
    for (int t = l; t < r; t++)
      ret = min(ret, dp(l, t, g - 1) + dp(t + 1, r, 1));
    return ret;
  }

public:
  int mergeStones(vector<int> &stoness, int KK) {
    stones = stoness;
    K = KK;
    n = stones.size();

    prev.resize(n + 1);
    for (int i = 1; i <= n; i++)
      prev[i] = prev[i - 1] + stones[i - 1];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k <= K; k++)
          mem[i][j][k] = -1;
      }
      mem[i][i][1] = 0;
    }

    int ans = dp(0, n - 1, 1);
    return ans >= MAX ? -1 : ans;
  }
};
