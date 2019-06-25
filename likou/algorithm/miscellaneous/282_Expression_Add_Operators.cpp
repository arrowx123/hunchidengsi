// 282_Expression_Add_Operators
// miscellaneous
typedef long long ll;

class Solution {
private:
  string num;
  int target;
  vector<string> ans;
  vector<string> ops;

  void bf(int pos, ll last, ll current, ll val) {
    if (pos == num.size()) {
      if (!current && val == target) {
        string tmp = "";
        for (int i = 1; i < ops.size(); i++)
          tmp += ops[i];
        ans.push_back(tmp);
      }
      return;
    }

    current = current * 10 + num[pos] - '0';
    string curStr = to_string(current);
    if (current) {
      bf(pos + 1, last, current, val);
    }

    ops.push_back("+");
    ops.push_back(curStr);
    bf(pos + 1, current, 0, val + current);
    ops.pop_back();
    ops.pop_back();

    if (ops.size()) {
      ops.push_back("-");
      ops.push_back(curStr);
      bf(pos + 1, -current, 0, val - current);
      ops.pop_back();
      ops.pop_back();

      ops.push_back("*");
      ops.push_back(curStr);
      bf(pos + 1, last * current, 0, val - last + last * current);
      ops.pop_back();
      ops.pop_back();
    }
    return;
  }

public:
  vector<string> addOperators(string num, int target) {
    this->num = num;
    this->target = target;

    bf(0, 0, 0, 0);
    return ans;
  }
};
