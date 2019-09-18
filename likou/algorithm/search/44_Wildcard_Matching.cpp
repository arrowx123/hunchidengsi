// 44_Wildcard_Matching
// dp
class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    int starI = -1, starJ = -1;
    while (i < s.size()) {
      if (j < p.size() && (p[j] == '?' || p[j] == s[i]))
        i++, j++;
      else if (j < p.size() && p[j] == '*') {
        starI = i;
        starJ = j;
        j++;
      } else if (starI == -1)
        return false;
      else {
        i = ++starI;
        j = starJ + 1;
      }
    }

    for (; j < p.size(); j++)
      if (p[j] != '*')
        return false;
    return true;
  }
};

// recursion with memorization
class Solution {
private:
  string s, p;
  int len;
  unordered_map<int, bool> umap;

  int getIdx(int i, int j) { return i * len + j; }

  bool match(int i, int j) {
    if (umap.count(getIdx(i, j)))
      return umap[getIdx(i, j)];
    if (j == p.size())
      return i == s.size();

    if (p[j] == '*')
      return umap[getIdx(i, j)] =
                 match(i, j + 1) || (i < s.size() && match(i + 1, j));
    return umap[getIdx(i, j)] =
               (i < s.size() && (s[i] == p[j] || p[j] == '?')) &&
               match(i + 1, j + 1);
  }

public:
  bool isMatch(string s, string p) {
    this->s = s;
    len = max(s.size(), p.size());
    for (int i = 0; i < p.size(); i++) {
      if ((this->p).size() && (this->p).back() == '*' && p[i] == '*')
        continue;
      else
        this->p += p[i];
    }
    return match(0, 0);
  }
};
