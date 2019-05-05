// 992_Subarrays_with_K_Different_Integers
// moving_window
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    unordered_map<int, int> count;
    int n = A.size();
    int ans = 0;
    int l = 0;
    int r = 0;
    while (r < n) {
      if (count.size() < K) {
        count[A[r]]++;
        r++;
      } else if (count.size() == K) {
        int i = r;
        for (; i < n; i++) {
          if (!count.count(A[i]))
            break;
        }
        ans += (i - r + 1);
        count[A[l]]--;
        if (!count[A[l]])
          count.erase(A[l]);
        l++;
      }
    }
    while (l < n) {
      if (count.size() == K)
        ans++;
      else
        break;

      count[A[l]]--;
      if (!count[A[l]])
        count.erase(A[l]);
      l++;
    }
    return ans;
  }
};
