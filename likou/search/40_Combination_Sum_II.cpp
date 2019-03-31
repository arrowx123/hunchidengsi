class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &tmp,
           int sum, int target, int pos) {
    if (sum == target) {
      ans.push_back(tmp);
    } else if (sum < target) {
      for (int i = pos; i < candidates.size(); i++) {
        if (i > pos && candidates[i] == candidates[i - 1])
          continue;
        if (sum + candidates[i] > target)
          break;
        tmp.push_back(candidates[i]);
        dfs(ans, candidates, tmp, sum + candidates[i], target, i + 1);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    dfs(ans, candidates, tmp, 0, target, 0);
    return ans;
  }
};
