// 1031_Maximum_Sum_of_Two_Non-Overlapping_Subarrays
// array
class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
    int n = A.size();
    vector<int> prefix(n);
    prefix[0] = A[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + A[i];
    }

    int bestL = prefix[L - 1];
    int bestR = prefix[M - 1];
    int ans = prefix[L + M - 1];
    for (int i = L + M; i < n; i++) {
      bestL = max(bestL, prefix[i - M] - prefix[i - M - L]);
      ans = max(ans, bestL + prefix[i] - prefix[i - M]);

      bestR = max(bestR, prefix[i - L] - prefix[i - L - M]);
      ans = max(ans, bestR + prefix[i] - prefix[i - L]);
    }

    return ans;
  }
};
