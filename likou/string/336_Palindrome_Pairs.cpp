class Solution {
private:
  unordered_map<string, int> umap;
  unordered_map<string, int> rumap;
  bool isPalindrome(const string &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }

public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> ans;
    for (int i = 0; i < words.size(); i++) {
      string tmp = words[i];
      reverse(tmp.begin(), tmp.end());
      umap[tmp] = i;
      rumap[words[i]] = i;
    }

    for (int i = 0; i < words.size(); i++) {
      string reverse_words = words[i];
      reverse(reverse_words.begin(), reverse_words.end());

      string left = "";
      string right = reverse_words;
      for (int j = 0; j <= words[i].size(); j++) {
        if (left.size() && isPalindrome(left) && rumap.count(right) &&
            rumap[right] != i)
          ans.push_back({rumap[right], i});
        if (isPalindrome(right) && umap.count(left) && umap[left] != i)
          ans.push_back({i, umap[left]});

        if (j < words[i].size()) {
          left += words[i][j];
          right.pop_back();
        }
      }
    }

    return ans;
  }
};
