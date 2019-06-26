// 91_Decode_Ways
// dp
class Solution {
public:
  int numDecodings(string s) {
    if (s.empty())
      return 0;
    if (s.size() == 1)
      return s[0] >= '1';

    int n = s.size();
    vector<int> cnt(n);

    if (s[0] >= '1')
      cnt[0] = 1;
    if (s[1] >= '1')
      cnt[1] += cnt[0];
    int num = (s[0] - '0') * 10 + s[1] - '0';
    if (num >= 10 && num <= 26)
      cnt[1]++;

    for (int i = 2; i < n; i++) {
      if (s[i] >= '1')
        cnt[i] += cnt[i - 1];
      int num = (s[i - 1] - '0') * 10 + s[i] - '0';
      if (num >= 10 && num <= 26)
        cnt[i] += cnt[i - 2];
    }
    return cnt[n - 1];
  }
};
