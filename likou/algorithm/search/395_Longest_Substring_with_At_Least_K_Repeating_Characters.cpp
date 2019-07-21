// 395_Longest_Substring_with_At_Least_K_Repeating_Characters
// search
class Solution {
private:
  int k;
  int bf(string &s, int l, int r) {
    unordered_map<char, int> cnt;
    for (int i = l; i < r; i++)
      cnt[s[i]]++;

    int ret = 0;
    for (int i = l; i < r; i++) {

      int start = i;
      while (start < r) {
        if (cnt[s[start]] >= k)
          break;
        start++;
      }

      int end = start;
      while (end < r) {
        if (cnt[s[end]] < k)
          break;
        end++;
      }

      if (start == l && end == r)
        return r - l;
      ret = max(ret, bf(s, start, end));
      i = end;
    }
    return ret;
  }

public:
  int longestSubstring(string s, int k) {
    this->k = k;
    return bf(s, 0, s.size());
  }
};
