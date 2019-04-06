// two pointers + recursion
class Solution {
public:
  string shortestPalindrome(string s) {

    int l = 0;
    int r = s.size() - 1;
    for (int j = s.size() - 1; j >= 0; j--) {
      if (s[j] == s[l])
        l++;
    }

    if (l == s.size())
      return s;

    string tmp = s.substr(l);
    reverse(tmp.begin(), tmp.end());
    return tmp + shortestPalindrome(s.substr(0, l)) + s.substr(l);
  }
};
