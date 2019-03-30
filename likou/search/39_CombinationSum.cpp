// dfs
class Solution {
private:
  void dfs(int pos, const int &target, vector<int> &tmp, int sum,
           vector<vector<int>> &ans, vector<int> &candidates) {
    if (sum == target) {
      ans.push_back(tmp);
    } else if (sum < target) {
      for (int i = pos; i < candidates.size(); i++) {
        tmp.push_back(candidates[i]);
        dfs(i, target, tmp, sum + candidates[i], ans, candidates);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> tmp;
    vector<vector<int>> ans;
    dfs(0, target, tmp, 0, ans, candidates);
    return ans;
  }
};
