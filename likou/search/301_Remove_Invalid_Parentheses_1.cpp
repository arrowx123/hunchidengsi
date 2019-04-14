// BT with pruning
class Solution {
private:
  unordered_set<string> uset;
  int max_len = INT_MIN;
  void dfs(string &tmp, const string &s, int pos, int left_added,
           int right_added, int left_remove, int right_remove) {
    if (pos == s.size()) {
      if (!left_remove && !right_remove) {
        if ((int)tmp.size() >= max_len) {
          uset.insert(tmp);
          max_len = max((int)tmp.size(), max_len);
        }
      }
    } else {
      if ((s[pos] == '(' && left_remove) || (s[pos] == ')' && right_remove)) {
        dfs(tmp, s, pos + 1, left_added, right_added,
            left_remove - (s[pos] == '(' ? 1 : 0),
            right_remove - (s[pos] == ')' ? 1 : 0));
      }
      if (s[pos] != '(' && s[pos] != ')') {
        tmp += s[pos];
        dfs(tmp, s, pos + 1, left_added, right_added, left_remove,
            right_remove);
        tmp.pop_back();
        return;
      }

      tmp += s[pos];
      if (s[pos] == '(') {
        dfs(tmp, s, pos + 1, left_added + 1, right_added, left_remove,
            right_remove);
      } else if (s[pos] == ')') {
        if (right_added < left_added) {
          dfs(tmp, s, pos + 1, left_added, right_added + 1, left_remove,
              right_remove);
        }
      }
      tmp.pop_back();
    }
    return;
  }

public:
  vector<string> removeInvalidParentheses(string s) {
    int left_remove = 0;
    int right_remove = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        left_remove++;
      else if (s[i] == ')') {
        if (left_remove) {
          left_remove--;
        } else {
          right_remove++;
        }
      }
    }

    string tmp = "";
    dfs(tmp, s, 0, 0, 0, left_remove, right_remove);

    vector<string> ans;
    for (auto ele : uset)
      if (ele.size() == max_len)
        ans.push_back(ele);
    return ans;
  }
};
