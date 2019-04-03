// permutation
class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &nums, int pos) {
    if (pos == nums.size()) {
      ans.push_back(nums);
    } else {
      unordered_set<int> uset;
      for (int i = pos; i < nums.size(); i++) {
        if (uset.count(nums[i]))
          continue;

        uset.insert(nums[i]);
        swap(nums[i], nums[pos]);
        dfs(ans, nums, pos + 1);
        swap(nums[i], nums[pos]);
      }
    }
    return;
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    dfs(ans, nums, 0);
    return ans;
  }
};
