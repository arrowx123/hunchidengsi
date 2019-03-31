// dfs
class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &tmp, int pos, int n, int k) {
    if (tmp.size() == k) {
      ans.push_back(tmp);
    } else {
      int len = tmp.size();
      for (int i = pos; i <= n - (k - len) + 1; i++) {
        tmp.push_back(i);
        dfs(ans, tmp, i + 1, n, k);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;
    dfs(ans, tmp, 1, n, k);
    return ans;
  }
};
