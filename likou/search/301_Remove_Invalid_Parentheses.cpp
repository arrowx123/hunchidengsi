// BT
class Solution {
private:
  unordered_set<string> uset;
  int max_len = INT_MIN;
  void dfs(string &tmp, const string &s, int pos, int left_added,
           int right_added) {
    if (pos == s.size()) {
      if (left_added == right_added) {
        if ((int)tmp.size() >= max_len) {
          uset.insert(tmp);
          max_len = max((int)tmp.size(), max_len);
        }
      }
    } else {
      if (s[pos] != '(' && s[pos] != ')') {
        tmp += s[pos];
        dfs(tmp, s, pos + 1, left_added, right_added);
        tmp.pop_back();
        return;
      }

      dfs(tmp, s, pos + 1, left_added, right_added);
      tmp += s[pos];
      if (s[pos] == '(') {
        dfs(tmp, s, pos + 1, left_added + 1, right_added);
      } else if (s[pos] == ')') {
        if (right_added < left_added) {
          dfs(tmp, s, pos + 1, left_added, right_added + 1);
        }
      }
      tmp.pop_back();
    }
    return;
  }

public:
  vector<string> removeInvalidParentheses(string s) {
    string tmp = "";
    dfs(tmp, s, 0, 0, 0);

    vector<string> ans;
    for (auto ele : uset)
      if (ele.size() == max_len)
        ans.push_back(ele);
    return ans;
  }
};
