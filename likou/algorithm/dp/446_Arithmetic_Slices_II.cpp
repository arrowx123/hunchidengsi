// 446_Arithmetic_Slices_II
// dp
typedef long long ll;
class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    vector<unordered_map<ll, int>> v(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        ll diff = (ll)A[i] - A[j];
        int cnt = v[j][diff];
        v[i][diff] += 1 + cnt;
        ans += cnt;
      }
    }
    return ans;
  }
};
