// bt
class Solution {
private:
  vector<string> ans;
  vector<string> segments;
  bool is_valid(string &s) {
    if (s.size() > 3)
      return false;
    if (stoi(s) > 255)
      return false;
    if (s[0] == '0' && s.size() > 1)
      return false;
    return true;
  }
  void add_to_answer() {
    string tmp = "";
    for (int i = 0; i < segments.size(); i++) {
      if (i)
        tmp += '.';
      tmp += segments[i];
    }
    ans.push_back(tmp);
  }
  void bt(string &s, int pos, int cnt) {
    int n = min((int)s.size() - pos - 1, 3);
    for (int i = 1; i <= n; i++) {
      string segment = s.substr(pos, i);
      if (is_valid(segment)) {
        segments.push_back(segment);
        if (cnt == 1) {
          segment = s.substr(pos + i);
          if (is_valid(segment)) {
            segments.push_back(segment);
            add_to_answer();
            segments.pop_back();
          }
        } else {
          bt(s, pos + i, cnt - 1);
        }
        segments.pop_back();
      }
    }
    return;
  }

public:
  vector<string> restoreIpAddresses(string s) {
    bt(s, 0, 3);
    return ans;
  }
};
