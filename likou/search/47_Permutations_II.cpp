// dfs
class Solution {
private:
  unordered_set<int> uset;
  void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums) {
    if (tmp.size() == nums.size()) {
      ans.push_back(tmp);
    } else {
      for (int i = 0; i < nums.size(); i++) {
        if (uset.count(i))
          continue;
        if (i && !uset.count(i - 1) && nums[i] == nums[i - 1])
          continue;
        tmp.push_back(nums[i]);
        uset.insert(i);
        dfs(ans, tmp, nums);
        uset.erase(i);
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    dfs(ans, tmp, nums);
    return ans;
  }
};
