// 1044_Longest_Duplicate_Substring
// sa

struct Suf {
  int idx;
  int rank[2];
};

bool cmp(Suf s1, Suf s2) {
  if (s1.rank[0] != s2.rank[0])
    return s1.rank[0] < s2.rank[0];
  return s1.rank[1] < s2.rank[1];
}

class Solution {
private:
  vector<int> sa;
  vector<int> lcp;

  void buildSuffixArray(string &S) {
    int n = S.size();
    vector<Suf> v(n);

    for (int i = 0; i < n; i++) {
      v[i].idx = i;
      v[i].rank[0] = S[i] - 'a';
      v[i].rank[1] = i < n - 1 ? S[i + 1] - 'a' : -1;
    }

    sort(v.begin(), v.end(), cmp);
    vector<int> inv(n);
    for (int k = 4; k < 2 * n; k *= 2) {

      int rank = 0;
      int r0 = v[0].rank[0];
      v[0].rank[0] = rank;
      inv[v[0].idx] = 0;
      for (int i = 1; i < n; i++) {
        if (v[i].rank[0] == r0 && v[i].rank[1] == v[i - 1].rank[1])
          v[i].rank[0] = rank;
        else {
          r0 = v[i].rank[0];
          v[i].rank[0] = ++rank;
        }
        inv[v[i].idx] = i;
      }

      for (int i = 0; i < n; i++) {
        int idx = v[i].idx + k / 2;
        v[i].rank[1] = idx >= n ? -1 : v[inv[idx]].rank[0];
      }
      sort(v.begin(), v.end(), cmp);
    }

    for (int i = 0; i < n; i++)
      sa.push_back(v[i].idx);
  }

  void buildLCP(string &S) {
    int n = sa.size();
    vector<int> inv(n);
    lcp.resize(n);

    for (int i = 0; i < n; i++)
      inv[sa[i]] = i;

    int k = 0;
    for (int i = 0; i < n; i++) {
      int idx = inv[i];
      if (idx == n - 1) {
        lcp[idx] = 0;
        continue;
      }

      int j = sa[idx + 1];
      while (i + k < n && j + k < n && S[i + k] == S[j + k])
        k++;
      lcp[idx] = k;
      if (k)
        k--;
    }
  }

public:
  string longestDupSubstring(string S) {
    int n = S.size();
    buildSuffixArray(S);
    buildLCP(S);

    string ans = "";
    int len = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (lcp[i] > len) {
        len = lcp[i];
        start = sa[i];
      }
    }

    ans = S.substr(start, len);
    return ans;
  }
};
