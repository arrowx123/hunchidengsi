// 300_Longest_Increasing_Subsequence
// binary search
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1)
      return n;

    vector<int> dp = {nums[0]};
    for (int i = 1; i < n; i++) {
      vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), nums[i]);
      int idx = it - dp.begin();
      if (idx >= dp.size())
        dp.push_back(nums[i]);
      else
        dp[idx] = nums[i];
    }
    return dp.size();
  }
};
