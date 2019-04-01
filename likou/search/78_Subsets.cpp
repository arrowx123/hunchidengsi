class Solution {
private:
  void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums,
           int pos) {
    ans.push_back(tmp);

    for (int i = pos; i < nums.size(); i++) {
      tmp.push_back(nums[i]);
      dfs(ans, tmp, nums, i + 1);
      tmp.pop_back();
    }
    return;
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> tmp;

    dfs(ans, tmp, nums, 0);
    return ans;
  }
};
