// dfs
class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &tmp, int sum, int pos, int k,
           int n) {
    if (tmp.size() == k) {
      if (sum == n) {
        ans.push_back(tmp);
      }
    } else {
      for (int i = pos; i <= 9 + 1 - (k - tmp.size()); i++) {
        tmp.push_back(i);
        dfs(ans, tmp, sum + i, i + 1, k, n);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> tmp;

    dfs(ans, tmp, 0, 1, k, n);
    return ans;
  }
};
