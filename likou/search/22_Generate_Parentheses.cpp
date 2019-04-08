// backtrack
class Solution {
private:
  void dfs(string &tmp, int l_cnt, vector<string> &ans, int len) {
    if (tmp.size() == len) {
      ans.push_back(tmp);
    } else {
      if ((int)tmp.size() - l_cnt <= l_cnt - 1) {
        tmp += ")";
        dfs(tmp, l_cnt, ans, len);
        tmp.pop_back();
      }
      if (l_cnt < len / 2) {
        tmp += "(";
        dfs(tmp, l_cnt + 1, ans, len);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<string> generateParenthesis(int n) {
    string tmp = "";
    vector<string> ans;
    dfs(tmp, 0, ans, 2 * n);
    return ans;
  }
};
