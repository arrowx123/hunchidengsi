// bf
class Solution {
private:
  bool is_valid(string &s) {
    int l = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        l++;
      else
        l--;
      if (l < 0)
        return false;
    }
    return l == 0;
  }
  void bf(vector<string> &ans, string &tmp, int pos, int len) {
    if (pos == len) {
      if (is_valid(tmp))
        ans.push_back(tmp);
    } else {
      tmp[pos] = '(';
      bf(ans, tmp, pos + 1, len);
      tmp[pos] = ')';
      bf(ans, tmp, pos + 1, len);
    }
    return;
  }

public:
  vector<string> generateParenthesis(int n) {
    string tmp = "";
    for (int i = 0; i < 2 * n; i++)
      tmp += "(";
    vector<string> ans;
    bf(ans, tmp, 0, 2 * n);
    return ans;
  }
};
