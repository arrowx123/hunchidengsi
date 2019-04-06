// KMP
class Solution {
private:
  void kmp(vector<int> &f, const string &s) {
    f[0] = 0;
    for (int i = 1; i < s.size(); i++) {
      int t = f[i - 1];
      while (t && s[t] != s[i])
        t = f[t - 1];
      if (s[t] == s[i])
        t++;
      f[i] = t;
    }
    return;
  }

public:
  string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string new_string = s + '#' + rev;

    vector<int> f(new_string.size());
    kmp(f, new_string);

    return rev.substr(0, s.size() - f[new_string.size() - 1]) + s;
  }
};
