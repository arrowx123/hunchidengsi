// bfs
class Solution {
private:
  unordered_map<int, string> umap = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                     {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                     {8, "tuv"}, {9, "wxyz"}};

public:
  vector<string> letterCombinations(string digits) {
    if (!digits.size())
      return vector<string>{};

    vector<string> v;
    vector<string> ans(1, "");

    for (int i = 0; i < digits.size(); i++) {
      v.push_back(umap[digits[i] - '0']);
    }

    for (int i = 0; i < v.size(); i++) {
      vector<string> tmp;
      for (int j = 0; j < v[i].size(); j++) {
        for (auto &s : ans) {
          tmp.push_back(s + v[i][j]);
        }
      }
      ans = tmp;
    }
    return ans;
  }
};
