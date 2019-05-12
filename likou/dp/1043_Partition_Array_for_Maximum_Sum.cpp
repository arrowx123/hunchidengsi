// 1043_Partition_Array_for_Maximum_Sum
// dp
class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    int n = A.size();
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
      dp[i] = A[i];
      int max_ = INT_MIN;
      for (int j = 1; j <= K; j++) {
        if (i - j + 1 < 0)
          break;
        max_ = max(max_, A[i - j + 1]);
        dp[i] = max(dp[i], (i - j >= 0 ? dp[i - j] : 0) + j * max_);
      }
    }
    return dp[n - 1];
  }
};
