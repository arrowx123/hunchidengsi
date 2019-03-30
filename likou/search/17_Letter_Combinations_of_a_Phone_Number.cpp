// dfs
class Solution {
private:
  unordered_map<int, string> umap = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                     {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                     {8, "tuv"}, {9, "wxyz"}};
  void dfs(vector<string> &v, string &tmp, vector<string> &ans, int pos) {
    if (tmp.size() == v.size()) {
      ans.push_back(tmp);
      return;
    }

    for (int i = 0; i < v[pos].size(); i++) {
      tmp += v[pos][i];
      dfs(v, tmp, ans, pos + 1);
      tmp.pop_back();
    }
    return;
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> v;
    vector<string> ans;
    if (!digits.size())
      return ans;

    for (int i = 0; i < digits.size(); i++) {
      v.push_back(umap[digits[i] - '0']);
    }

    string tmp = "";
    dfs(v, tmp, ans, 0);
    return ans;
  }
};
