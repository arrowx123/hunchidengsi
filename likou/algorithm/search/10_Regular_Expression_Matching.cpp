// 10_Regular_Expression_Matching
// O(mn)
// bottom up
class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> v(m + 1, vector<bool>(n + 1));
    v[m][n] = true;

    for (int i = m; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        if (j < n - 1 && p[j + 1] == '*')
          v[i][j] = v[i][j + 2] || (match && v[i + 1][j]);
        else
          v[i][j] = match && v[i + 1][j + 1];
      }
    }
    return v[0][0];
  }
};

// O(mn)
// top down
class Solution {
private:
  string s, p;
  int len;
  unordered_map<int, bool> umap;

  int getIdx(int i, int j) { return i * len + j; }

  bool recursion(int l, int r) {
    if (umap.count(getIdx(l, r)))
      return umap[getIdx(l, r)];
    if (r == p.size())
      return l == s.size();

    bool match = l < s.size() && (s[l] == p[r] || p[r] == '.');
    if (r + 1 < p.size() && p[r + 1] == '*')
      return umap[getIdx(l, r)] =
                 recursion(l, r + 2) || (match && recursion(l + 1, r));
    return umap[getIdx(l, r)] = match && recursion(l + 1, r + 1);
  }

public:
  bool isMatch(string ss, string pp) {
    s = ss;
    p = pp;
    len = max(s.size(), p.size());
    return recursion(0, 0);
  }
};
