class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &A) {
    int ans = INT_MIN;
    int most = INT_MIN;

    for (int i = 0; i < A.size(); i++) {
      ans = max(ans, A[i] + most - i);
      most = max(most, A[i] + i);
    }

    return ans;
  }
};
