class Solution {
public:
  string longestPalindrome(string s) {
    vector<bool> odd(s.size(), true);
    vector<bool> even(s.size(), true);

    int pos = 0;
    int max_len = 1;
    for (int i = 1; i <= s.size() / 2; i++) {
      for (int j = i; j < s.size() - i; j++) {
        if (odd[j] && s[j - i] == s[j + i]) {
          if (max_len < 2 * i + 1) {
            max_len = 2 * i + 1;
            pos = j;
          }
        } else
          odd[j] = false;
      }
    }

    for (int i = i; i <= s.size() / 2; i++) {
      for (int j = i - 1; j < s.size() - i; j++) {
        if (even[j] && s[j + 1 - i] == s[j + i]) {
          if (max_len < 2 * i) {
            max_len = 2 * i;
            pos = j;
          }
        } else
          even[j] = false;
      }
    }

    string ans = "";
    if (max_len % 2) {
      ans = s.substr(pos - max_len / 2, max_len);
    } else {
      ans = s.substr(pos - max_len / 2 + 1, max_len);
    }
    return ans;
  }
};
