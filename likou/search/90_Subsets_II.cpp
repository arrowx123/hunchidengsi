// dfs
class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums,
           int pos) {
    ans.push_back(tmp);
    for (int i = pos; i < nums.size(); i++) {
      if (i > pos && nums[i] == nums[i - 1])
        continue;
      tmp.push_back(nums[i]);
      dfs(ans, tmp, nums, i + 1);
      tmp.pop_back();
    }
    return;
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> tmp;

    dfs(ans, tmp, nums, 0);
    return ans;
  }
};
