// 424_Longest_Repeating_Character_Replacement
// sliding_window
class Solution {
private:
  unordered_map<char, int> umap;
  int get_max() {
    int max_ = 0;
    for (auto tuple : umap)
      max_ = max(max_, tuple.second);
    return max_;
  }

public:
  int characterReplacement(string s, int k) {
    int l = 0, r = 0, ans = 0;
    while (r < s.size()) {
      umap[s[r++]]++;
      if (r - l - get_max() <= k)
        ans = max(ans, r - l);
      else
        umap[s[l++]]--;
    }
    return ans;
  }
};
