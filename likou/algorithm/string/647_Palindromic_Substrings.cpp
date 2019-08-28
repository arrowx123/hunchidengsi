// 647_Palindromic_Substrings
// O(n)
// Manacher
// https://leetcode.com/problems/palindromic-substrings/solution/
class Solution {
public:
  int countSubstrings(string s) {
    string ss = "";
    ss += '@';
    for (auto c : s) {
      ss += '#';
      ss += c;
    }
    ss += "#&";

    vector<int> l(ss.size());
    int right = -1, center = -1;
    for (int i = 1; i < l.size() - 1; i++) {
      if (i < right)
        l[i] = min(right - i, l[2 * center - i]);
      while (ss[i + l[i] + 1] == ss[i - l[i] - 1])
        l[i]++;
      if (i + l[i] > right) {
        right = i + l[i];
        center = i;
      }
    }
    int ans = 0;
    for (auto e : l)
      ans += (e + 1) / 2;
    return ans;
  }
};
