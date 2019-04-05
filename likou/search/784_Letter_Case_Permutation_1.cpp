// bfs
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans = {""};
    for (int i = 0; i < S.size(); i++) {
      int len = ans.size();
      if (isdigit(S[i])) {
        for (int j = 0; j < len; j++)
          ans[j] += S[i];
      } else {
        char c = tolower(S[i]);
        for (int j = 0; j < len; j++) {
          ans.push_back(ans[j]);
          ans.back() += char(c - 'a' + 'A');
          ans[j] += c;
        }
      }
    }
    return ans;
  }
};
