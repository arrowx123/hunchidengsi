// 673_Number_of_Longest_Increasing_Subsequence
// dp
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    int maxLen = 1;
    vector<int> dp(n);
    vector<int> count(n);

    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      count[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            count[i] = count[j];
            maxLen = max(maxLen, dp[i]);
          } else if (dp[j] + 1 == dp[i]) {
            count[i] += count[j];
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] == maxLen)
        ans += count[i];
    }
    return ans;
  }
};
