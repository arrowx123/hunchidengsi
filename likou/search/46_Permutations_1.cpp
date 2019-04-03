// permutation
class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &nums, int pos) {
    if (pos == nums.size())
      ans.push_back(nums);

    for (int i = pos; i < nums.size(); i++) {
      swap(nums[pos], nums[i]);
      dfs(ans, nums, pos + 1);
      swap(nums[pos], nums[i]);
    }
    return;
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    dfs(ans, nums, 0);
    return ans;
  }
};
