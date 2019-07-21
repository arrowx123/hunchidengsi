// 395_Longest_Substring_with_At_Least_K_Repeating_Characters
// sliding_window
class Solution {
public:
  int longestSubstring(string s, int k) {
    unordered_map<char, int> cnt;
    for (auto c : s)
      cnt[c]++;

    int len = 0;
    for (auto ele : cnt) {
      if (ele.second >= k)
        len++;
    }

    int ans = 0;
    for (int i = 0; i < len; i++) {
      int l = 0, r = 0, uniq_cnt = 0;
      unordered_map<char, int> ccnt;
      while (r < s.size()) {
        if (ccnt[s[r++]]++ == k - 1)
          uniq_cnt++;
        while (ccnt.size() > i + 1) {
          if (ccnt[s[l++]]-- == k)
            uniq_cnt--;
          if (!ccnt[s[l - 1]])
            ccnt.erase(s[l - 1]);
        }
        if (uniq_cnt == i + 1)
          ans = max(ans, r - l);
      }
    }
    return ans;
  }
};
