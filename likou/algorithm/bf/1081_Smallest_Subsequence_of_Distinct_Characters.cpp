// 1081_Smallest_Subsequence_of_Distinct_Characters
// bf
class Solution {
public:
  string smallestSubsequence(string text) {
    if (!text.size())
      return "";

    unordered_map<char, int> cnt;
    int n = text.size();
    for (int i = 0; i < n; i++)
      cnt[text[i]]++;

    char c = 'z' + 1;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (text[i] < c) {
        c = text[i];
        pos = i;
      }
      cnt[text[i]]--;
      if (!cnt[text[i]])
        break;
    }

    string rest = "";
    for (int i = pos + 1; i < n; i++) {
      if (text[i] != c)
        rest += text[i];
    }

    return c + smallestSubsequence(rest);
  }
};
