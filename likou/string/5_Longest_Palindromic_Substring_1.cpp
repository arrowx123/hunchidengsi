// bf
class Solution {
private:
  int max_len = INT_MIN;
  int pos = -1;
  void check(int l, int r, string &s) {
    while (l >= 0 && r < s.size()) {
      if (s[l] != s[r])
        break;

      if (r - l + 1 > max_len) {
        max_len = r - l + 1;
        pos = l;
      }
      l--;
      r++;
    }
    return;
  }

public:
  string longestPalindrome(string s) {
    if (s.size() < 1)
      return s;

    for (int i = 0; i < s.size(); i++) {
      check(i, i, s);
      check(i, i + 1, s);
    }
    return s.substr(pos, max_len);
  }
};
