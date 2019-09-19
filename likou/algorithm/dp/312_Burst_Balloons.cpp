// 312_Burst_Balloons
// O(n^3)
// dp
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int len = 1; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int l = i;
        int r = i + len - 1;
        for (int j = l; j <= r; j++)
          dp[l][r] = max(dp[l][r], nums[l - 1] * nums[j] * nums[r + 1] +
                                       dp[l][j - 1] + dp[j + 1][r]);
      }
    }
    return dp[1][n];
  }
};
