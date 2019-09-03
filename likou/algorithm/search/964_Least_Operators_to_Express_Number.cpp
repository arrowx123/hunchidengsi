// 964_Least_Operators_to_Express_Number
// O(logx(target))
class Solution {
private:
  unordered_map<string, int> cnt;
  int x;
  int dp(int i, int target) {
    string key = to_string(i) + "#" + to_string(target);
    if (cnt.count(key))
      return cnt[key];
    if (target == 0)
      return 0;
    else if (target == 1)
      return cost(i);

    int t = target / x;
    int r = target % x;
    int ans = r * cost(i) + dp(i + 1, t);
    if (r)
      ans = min(ans, (x - r) * cost(i) + dp(i + 1, t + 1));
    return cnt[key] = ans;
  }

  int cost(int i) { return i > 0 ? i : 2; }

public:
  int leastOpsExpressTarget(int x, int target) {
    this->x = x;
    return dp(0, target) - 1;
  }
};
