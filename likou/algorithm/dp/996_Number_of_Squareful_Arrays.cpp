// 996_Number_of_Squareful_Arrays
// SCDP
// O(n*2^n)
class Solution {
private:
  vector<int> A;
  vector<vector<bool>> pair;
  vector<vector<int>> mem;
  int len;

  int dp(int mask, int p) {
    if (mask == (1 << len) - 1)
      return 1;
    if (mem[mask][p] >= 0)
      return mem[mask][p];

    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (mask & (1 << i))
        continue;
      if (!pair[p][i])
        continue;
      ans += dp((mask | (1 << i)), i);
    }
    return mem[mask][p] = ans;
  }

  int fac(int n) {
    int ret = 1;
    while (n--)
      ret *= (n + 1);
    return ret;
  }

public:
  int numSquarefulPerms(vector<int> &AA) {
    A = AA;
    len = A.size();

    pair.resize(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        int d = sqrt(A[i] + A[j]);
        pair[i][j] = (d * d == A[i] + A[j]);
      }
    }

    mem.resize((1 << len), vector<int>(len, -1));
    int ans = 0;
    for (int i = 0; i < len; i++)
      ans += dp((1 << i), i);

    unordered_map<int, int> cnt;
    for (int i : A)
      cnt[i]++;
    for (auto ele : cnt)
      ans /= fac(ele.second);
    return ans;
  }
};
