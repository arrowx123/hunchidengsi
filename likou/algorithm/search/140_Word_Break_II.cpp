// 140_Word_Break_II
// recursion with memorization
// O(n^2)
class Solution {
private:
  unordered_set<string> uset;
  unordered_map<int, vector<string>> umap;
  string s;
  vector<string> dfs(int pos) {
    if (pos == s.size())
      return {""};
    if (umap.count(pos))
      return umap[pos];

    string tmp = "";
    vector<string> cur;
    for (int i = pos; i < s.size(); i++) {
      tmp += s[i];
      if (uset.count(tmp)) {
        vector<string> vec = dfs(i + 1);
        for (auto str : vec)
          cur.push_back(str.size() ? tmp + " " + str : tmp);
      }
    }
    return umap[pos] = cur;
  }

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    for (string &word : wordDict)
      uset.insert(word);
    this->s = s;
    return dfs(0);
  }
};
