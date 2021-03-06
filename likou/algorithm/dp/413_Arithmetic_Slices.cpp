// 413_Arithmetic_Slices
// dp
class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    int n = A.size();
    int ans = 0, dp = 0;

    for (int i = 2; i < n; i++) {
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        dp += 1;
        ans += dp;
      } else
        dp = 0;
    }

    return ans;
  }
};
