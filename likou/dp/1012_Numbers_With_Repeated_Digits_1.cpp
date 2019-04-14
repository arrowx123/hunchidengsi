// dp
class Solution {
private:
  int dp[20][1 << 10][2];
  int solve(int pos, int mask, int match, const string &num) {
    if (pos >= num.size()) {
      return 1;
    }

    int &val = dp[pos][mask][match];
    if (val >= 0)
      return val;

    val = 0;
    for (int digit = 0; digit < 10; digit++) {
      if (match && digit > num[pos] - '0')
        break;
      ;

      if (mask & (1 << digit))
        continue;

      val += solve(pos + 1, (mask == 0 && digit == 0) ? 0 : mask | (1 << digit),
                   match && digit == num[pos] - '0', num);
    }
    return val;
  }

public:
  int numDupDigitsAtMostN(int N) {
    string num = to_string(N);
    memset(dp, -1, sizeof(dp));
    return N - solve(0, 0, true, num) + 1;
  }
};
