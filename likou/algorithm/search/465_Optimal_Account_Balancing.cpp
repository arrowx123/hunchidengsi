// 465_Optimal_Account_Balancing
// dp
class Solution {
public:
  int minTransfers(vector<vector<int>> &transactions) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < transactions.size(); i++) {
      vector<int> &t = transactions[i];
      cnt[t[0]] -= t[2];
      cnt[t[1]] += t[2];
    }

    vector<int> v;
    for (auto ele : cnt) {
      if (ele.second)
        v.push_back(ele.second);
    }

    vector<int> dp(1 << v.size());
    vector<int> sum(1 << v.size());

    for (int i = 0; i < 1 << v.size(); i++) {
      int digit = 1;
      for (int j = 0; j < v.size(); j++) {
        if ((i & digit) == 0) {
          int next = i | digit;
          sum[next] = v[j] + sum[i];

          if (!sum[next])
            dp[next] = max(dp[next], dp[i] + 1);
          else
            dp[next] = max(dp[next], dp[i]);
        }
        digit <<= 1;
      }
    }
    return v.size() - dp[(1 << v.size()) - 1];
  }
};
