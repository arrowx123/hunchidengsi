// 395_Longest_Substring_with_At_Least_K_Repeating_Characters
// search
class Solution {
private:
  int k;
  int bf(string &s, int l, int r) {
    cout << l << " " << r << endl;

    if (l == r)
      return 0;
    unordered_map<char, int> cnt;
    for (int i = l; i < r; i++)
      cnt[s[i]]++;

    int i = l;
    for (; i < r; i++)
      if (cnt[s[i]] >= k)
        break;
    int len = r - i;
    for (; i < r; i++) {
      if (cnt[s[i]] < k) {
        int cnt1 = bf(s, l, i);
        int cnt2 = bf(s, i + 1, r);
        return max(cnt1, cnt2);
      }
    }
    return len;
  }

public:
  int longestSubstring(string s, int k) {
    this->k = k;
    return bf(s, 0, s.size());
  }
};
