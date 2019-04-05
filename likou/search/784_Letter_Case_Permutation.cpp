// dfs
class Solution {
private:
  void dfs(vector<string> &ans, string &S, int pos, string &tmp) {
    if (pos == S.size()) {
      ans.push_back(tmp);
    } else {
      if (isdigit(S[pos])) {
        tmp += S[pos];
        dfs(ans, S, pos + 1, tmp);
        tmp.pop_back();
      } else {
        tmp += toupper(S[pos]);
        dfs(ans, S, pos + 1, tmp);
        tmp.pop_back();

        tmp += tolower(S[pos]);
        dfs(ans, S, pos + 1, tmp);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    string tmp;
    dfs(ans, S, 0, tmp);
    return ans;
  }
};
