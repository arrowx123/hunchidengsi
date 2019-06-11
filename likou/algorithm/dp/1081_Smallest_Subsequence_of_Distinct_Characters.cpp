// 1081_Smallest_Subsequence_of_Distinct_Characters
// dp
class Solution {
private:
  bool contain(int a, int b) { return (a & b) == b; }

public:
  string smallestSubsequence(string text) {
    int n = text.size();
    vector<int> dp(n + 1);

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = dp[i + 1] | (1 << (text[i] - 'a'));
    }

    int rem = dp[0];
    int pos = 0;
    int len = __builtin_popcount(rem);

    string ret = "";
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < 26; j++) {
        if (!(rem & (1 << j)))
          continue;
        int cp = pos;
        while (cp < n && text[cp] != 'a' + j)
          cp++;
        if (contain(dp[cp], rem)) {
          ret += 'a' + j;
          pos = cp + 1;
          rem ^= (1 << j);
          break;
        }
      }
    }
    return ret;
  }
};
