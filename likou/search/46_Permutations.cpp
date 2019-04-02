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
        uset.insert(i);
        tmp.push_back(nums[i]);
        dfs(ans, tmp, nums);
        tmp.pop_back();
        uset.erase(i);
      }
    }
    return;
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> tmp;

    dfs(ans, tmp, nums);
    return ans;
  }
};
